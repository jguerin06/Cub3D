/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:24:04 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/25 03:39:13 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

uint32_t calculate_wall_color(float dist) {
	if (dist > 400)
		return get_rgba(168, 156, 148, 255);
	else if (dist > 300)
		return get_rgba(191, 174, 164, 255);
	else
		return get_rgba(214, 192, 179, 255);
}

int calc_wall_height(float dist)
{
	int wall_height = (MAPSQUARE * HEIGHT) / dist;

	if (wall_height > HEIGHT)
		wall_height = HEIGHT;

	return wall_height;
}

void render_wall(t_opt *opt, int ray_index, float dist)
{
	int wall_height = calc_wall_height(dist);
	int start_y = (HEIGHT / 2) - (wall_height / 2);
	int end_y = start_y + wall_height;

	if (start_y < 0) start_y = 0;
	if (end_y > HEIGHT) end_y = HEIGHT;
	for (int y = start_y; y < end_y; y++) {
		uint32_t wall_color = calculate_wall_color(dist);
		mlx_put_pixel(opt->wall_img, ray_index, y, wall_color);
	}
}

float cast_ray(t_opt *opt, float ray_angle)
{
	float ray_x = opt->x;
	float ray_y = opt->y;
	float ray_dir_x = cos(ray_angle);
	float ray_dir_y = sin(ray_angle);
	int i = 0;

	while (i < 100)
	{
		ray_x += ray_dir_x * 5;
		ray_y += ray_dir_y * 5;
		if (opt->map[(int)(ray_y / MAPSQUARE)][(int)(ray_x / MAPSQUARE)] == '1')
			break;
		i++;
	}
	float dist = sqrt((ray_x - opt->x) * (ray_x - opt->x) + (ray_y - opt->y) * (ray_y - opt->y));
	return dist;
}

void draw_3d(t_opt *opt)
{
	int ray_index = 0;
	float fov = 90 * (PI / 180);
	float start_angle = opt->pa - (fov / 2);
	float angle_step = fov / WIDTH;
	if (opt->wall_img)
		mlx_delete_image(opt->mlx, opt->wall_img);
	opt->wall_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(opt->mlx, opt->wall_img, 0, 0);
	opt->wall_img->instances[0].z = 1;
	while (ray_index < WIDTH) {
		// Angle du rayon courant
		float ray_angle = start_angle + ray_index * angle_step;
		float dist = cast_ray(opt, ray_angle);
		float corrected_dist = dist * cos(ray_angle - opt->pa);
		render_wall(opt, ray_index, corrected_dist);
		ray_index++;
	}
}

void	draw_ray(t_opt *opt)
{
	int num_rays = 100;
	float fov = 90 * (PI / 180);
	float start_angle = opt->pa - (fov / 2);
	float angle_step = fov / num_rays;

	if (opt->ray_img)
		mlx_delete_image(opt->mlx, opt->ray_img);
	opt->ray_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(opt->mlx, opt->ray_img, 0, 0);
	opt->ray_img->instances[0].z = 4;
	for (int r = 0; r < num_rays; r++)
	{
		float current_angle = start_angle + r * angle_step;
		float ray_dir_x = cos(current_angle) * 1.1;
		float ray_dir_y = sin(current_angle) * 1.1;
		float ray_x = opt->x;
		float ray_y = opt->y;
		int i = 0;
		while (i < 500)
		{
			ray_x += ray_dir_x;
			ray_y += ray_dir_y;
			if (opt->map[(int)(ray_y / MAPSQUARE)][(int)(ray_x / MAPSQUARE)] == '1')
				break;
			mlx_put_pixel(opt->ray_img, ray_x, ray_y, get_rgba(0, 255, 0, 255));
			i++;
		}
	}
}
