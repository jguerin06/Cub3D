/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:01:16 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/27 12:12:57 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_wall(t_opt *opt, int ray_index, double dist, int facing,
		double border_dist)
{
	int	wall_height;
	int	start_y;
	int	end_y;
	int	y;
	int	color;

	wall_height = (MAPSQUARE * HEIGHT) / dist;
	start_y = (HEIGHT / 2) - (wall_height / 2);
	end_y = start_y + wall_height;
	y = start_y;
	if (y < 0)
		y = 0;
	if (end_y > HEIGHT)
		end_y = HEIGHT;
	while (y < end_y)
	{
		color = find_pixel_color(opt->textures[facing], border_dist
				* opt->textures[facing]->width, (y - start_y)
				* opt->textures[facing]->height / wall_height);
		mlx_put_pixel(opt->wall_img, ray_index, y, color);
		y++;
	}
}

int	is_vertical(double x, double y)
{
	return (fabs(x - round(x)) < fabs(y - round(y)));
}

double	cast_ray(t_opt *opt, double ray_angle)
{
	double	ray_x;
	double	ray_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		i;
	double	dist;

	ray_x = opt->x;
	ray_y = opt->y;
	ray_dir_x = cos(ray_angle);
	ray_dir_y = sin(ray_angle);
	i = 0;
	while (i < 100)
	{
		ray_x += ray_dir_x * 5;
		ray_y += ray_dir_y * 5;
		if (opt->map[(int)(ray_y / MAPSQUARE)][(int)(ray_x / MAPSQUARE)] == '1')
			break ;
		i++;
	}
	dist = sqrt((ray_x - opt->x) * (ray_x - opt->x) + (ray_y - opt->y)
			* (ray_y - opt->y));
	return (dist);
}
// fonction inutilisee, jsp ce que tu voulais en faire
