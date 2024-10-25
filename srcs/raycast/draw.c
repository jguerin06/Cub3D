/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:22:53 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/24 16:49:34 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_celling(t_opt *opt, t_infomap map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	opt->celling_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT / 2);
	mlx_image_to_window(opt->mlx, opt->celling_img, 0, 0);
	opt->celling_img->instances[0].z = 0;
	while (i < HEIGHT / 2)
	{
		while (j < WIDTH)
		{
			mlx_put_pixel(opt->celling_img, j, i, get_rgba(map.ceiling_color[0],
					map.ceiling_color[1], map.ceiling_color[2], 255));
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_floor(t_opt *opt, t_infomap map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	opt->floor_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT / 2);
	mlx_image_to_window(opt->mlx, opt->floor_img, 0, HEIGHT / 2);
	opt->floor_img->instances[0].z = 0;
	while (i < HEIGHT / 2)
	{
		while (j < WIDTH)
		{
			mlx_put_pixel(opt->floor_img, j, i, get_rgba(map.floor_color[0], \
				map.floor_color[1], map.floor_color[2], 255));
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_square(t_opt *opt, int x, int y, uint32_t color)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < MAPSQUARE)
	{
		mlx_put_pixel(opt->map_img, x + i, y, BLACK);
		mlx_put_pixel(opt->map_img, x + i, y + MAPSQUARE - 1, BLACK);
		mlx_put_pixel(opt->map_img, x, y + i, BLACK);
		mlx_put_pixel(opt->map_img, x + MAPSQUARE - 1, y + i, BLACK);
		i++;
	}
	j = 1;
	while (j < MAPSQUARE - 1)
	{
		k = 1;
		while (k < MAPSQUARE - 1)
		{
			mlx_put_pixel(opt->map_img, x + k, y + j, color);
			k++;
		}
		j++;
	}
}

void	draw_map(t_opt *opt, t_infomap map)
{
	int		i;
	int		j;

	i = 0;
	opt->map_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(opt->mlx, opt->map_img, 0, 0);
	while (i < map.height)
	{
		j = 0;
		while (j < (int)ft_strlen(opt->map[i]))
		{
			if (opt->map[i][j] == '1')
				draw_square(opt, j * MAPSQUARE, i * MAPSQUARE, WALL);
			else if (opt->map[i][j] == '0' || opt->map[i][j] == 'N' || opt->map[i][j] == 'S' || opt->map[i][j] == 'E' || opt->map[i][j] == 'W')
				draw_square(opt, j * MAPSQUARE, i * MAPSQUARE, FLOOR);
			j++;
		}
		i++;
	}
	opt->map_img->instances[0].z = 3;
}
