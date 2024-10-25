/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:23:43 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/24 04:04:24 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_facing(t_opt *opt)
{
	if (opt->direction == 'N')
		opt->pa = PI / 2;
	else if (opt->direction == 'S')
		opt->pa = 3 * PI / 2;
	else if (opt->direction == 'W')
		opt->pa = PI;
	else if (opt->direction == 'E')
		opt->pa = 0;
}

void	init_player(t_opt *opt)
{
	init_facing(opt);
	opt->pdx = cos(opt->pa) * PLRSPEED;
	opt->pdy = sin(opt->pa) * PLRSPEED;
	opt->x = opt->pos_x * MAPSQUARE - MAPSQUARE / 2;
	opt->y = opt->pos_y * MAPSQUARE - MAPSQUARE / 2;
}

void	put_player(t_opt *opt)
{
	int i;
	int j;

	i = 0;
	j = 0;
	opt->plr_img = mlx_new_image(opt->mlx, 15, 15);
	mlx_image_to_window(opt->mlx, opt->plr_img, opt->x, opt->y);
	while (i < 15)
	{
		while (j < 15)
		{
			mlx_put_pixel(opt->plr_img, opt->x + i, opt->y + j, get_rgba(129, 104, 157, 255));
			j++;
		}
		j = 0;
		i++;
	}
	init_player(opt);
	opt->plr_img->instances[0].z = 5;
}
