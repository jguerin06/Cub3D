/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:24:04 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/27 11:57:35 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_pixel_color(mlx_texture_t *texture, int x, int y)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = texture->pixels[(y * texture->width + x) * 4];
	g = texture->pixels[(y * texture->width + x) * 4 + 1];
	b = texture->pixels[(y * texture->width + x) * 4 + 2];
	a = texture->pixels[(y * texture->width + x) * 4 + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

t_vector	wall_intersector(t_vector v1, double a1, t_vector v2, double a2)
{
	t_vector	intersection;
	double		t;

	intersection.hit = 0;
	if (a1 == a2)
		return (intersection);
	t = ((v2.y - v1.y) * cos(a2) - (v2.x - v1.x) * sin(a2)) / sin(a1 - a2);
	intersection.x = v1.x + cos(a1) * t;
	intersection.y = v1.y + sin(a1) * t;
	intersection.hit = 1;
	return (intersection);
}

t_vector	next_grid_intersector(t_vector player, double angle, int x, int y)
{
	int			dir_facing_pos;
	t_vector	inter_h;
	t_vector	inter_v;

	x = (int)floor(player.x / MAPSQUARE);
	y = (int)floor(player.y / MAPSQUARE);
	dir_facing_pos = 1;
	if (sin(angle) <= 0)
		dir_facing_pos = 0;
	inter_h = wall_intersector((t_vector){player.x, player.y, 0}, angle,
			(t_vector){0, (y + dir_facing_pos) * MAPSQUARE, 0}, 0);
	dir_facing_pos = 1;
	if (cos(angle) <= 0)
		dir_facing_pos = 0;
	inter_v = wall_intersector((t_vector){player.x, player.y, 0}, angle,
			(t_vector){(x + dir_facing_pos) * MAPSQUARE, 0, 0}, PI / 2);
	if (!inter_h.hit)
		return (inter_v);
	else if (!inter_v.hit)
		return (inter_h);
	else if (pow(player.x - inter_h.x, 2) + pow(player.y - inter_h.y,
			2) < pow(player.x - inter_v.x, 2) + pow(player.y - inter_v.y, 2))
		return (inter_h);
	else
		return (inter_v);
}

void	draw_ray(t_opt *opt)
{
	t_vector	next;

	if (opt->ray_img)
		mlx_delete_image(opt->mlx, opt->ray_img);
	opt->ray_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(opt->mlx, opt->ray_img, 0, 0);
	opt->ray_img->instances[0].z = 6;
	next = (t_vector){opt->x, opt->y, 0};
	while (1)
	{
		next = next_grid_intersector(next, opt->pa, 0, 0);
		next.x += cos(opt->pa);
		next.y += sin(opt->pa);
		draw_little_square(opt->ray_img, floor(next.x / MAPSQUARE) * MAPSQUARE
			+ MAPSQUARE / 2, floor(next.y / MAPSQUARE) * MAPSQUARE
			+ MAPSQUARE / 2, 15, get_rgba(0, 0, 255, 255));
		if (opt->map[(int)(next.y / MAPSQUARE)][(int)(next.x
				/ MAPSQUARE)] == '1')
		{
			draw_little_square(opt->ray_img, next.x, next.y, 15,
				get_rgba(0, 0, 0, 255));
			break ;
		}
		draw_little_square(opt->ray_img, next.x, next.y, 15, get_rgba(0, 255, 0, 255));
	}
}

void	draw_3d(t_opt *opt)
{
	int			ray_index;
	double		fov;
	double		start_angle;
	double		angle_step;
	double		cos_angle;
	double		sin_angle;
	t_vector	next;
	int			facing;
	double		next_x;
	double		next_y;
	double		dist;

	ray_index = 0;
	fov = 90 * (PI / 180);
	start_angle = opt->pa - (fov / 2);
	angle_step = fov / WIDTH;
	if (opt->wall_img)
		mlx_delete_image(opt->mlx, opt->wall_img);
	opt->wall_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(opt->mlx, opt->wall_img, 0, 0);
	opt->wall_img->instances[0].z = 1;
	while (ray_index < WIDTH)
	{
		next = (t_vector){opt->x, opt->y, 0};
		while (1)
		{
			cos_angle = cos(start_angle + angle_step * ray_index);
			sin_angle = sin(start_angle + angle_step * ray_index);
			next = next_grid_intersector(next, start_angle + angle_step
					* ray_index, 0, 0);
			next_x = next.x;
			next_y = next.y;
			next.x += cos_angle / 100;
			next.y += sin_angle / 100;
			if (opt->map[(int)(next.y / MAPSQUARE)][(int)(next.x
					/ MAPSQUARE)] == '1')
			{
				if (cos_angle > 0)
				{
					if (sin_angle > 0)
					{
						if (is_vertical(next_x, next_y))
							facing = 1;
						else
							facing = 0;
					}
					else
					{
						if (is_vertical(next_x, next_y))
							facing = 1;
						else
							facing = 2;
					}
				}
				else
				{
					if (sin_angle > 0)
					{
						if (is_vertical(next_x, next_y))
							facing = 3;
						else
							facing = 0;
					}
					else
					{
						if (is_vertical(next_x, next_y))
							facing = 3;
						else
							facing = 2;
					}
				}
				dist = sqrt((next_x - opt->x) * (next_x - opt->x) + (next_y
							- opt->y) * (next_y - opt->y));
				render_wall(opt, ray_index, dist, facing, facing % 2
					* fmod((next_y) / MAPSQUARE, 1) + (1 - facing % 2)
					* fmod((next_x) / MAPSQUARE, 1));
				break ;
			}
		}
		ray_index++;
	}
}
