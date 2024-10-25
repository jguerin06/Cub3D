/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:00:04 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/24 07:00:43 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_opt *opt)
{
	opt->pa -= 0.1;
	if (opt->pa < 0)
		opt->pa += 2 * PI;
	opt->pdx = cos(opt->pa) * PLRSPEED;
	opt->pdy = sin(opt->pa) * PLRSPEED;
}

void	turn_right(t_opt *opt)
{
	opt->pa += 0.1;
	if (opt->pa > 2 * PI)
		opt->pa -= 2 * PI;
	opt->pdx = cos(opt->pa) * PLRSPEED;
	opt->pdy = sin(opt->pa) * PLRSPEED;
}

void	go_right(t_opt *opt)
{
	if (opt->map[(int)((opt->y + opt->pdx) / MAPSQUARE)][(int)((opt->x - opt->pdy) / MAPSQUARE)] == '1')
		return;
	opt->x -= opt->pdy;
	opt->y += opt->pdx;
}

void	go_left(t_opt *opt)
{
	if (opt->map[(int)((opt->y - opt->pdx) / MAPSQUARE)][(int)((opt->x + opt->pdy) / MAPSQUARE)] == '1')
		return;
	opt->x += opt->pdy;
	opt->y -= opt->pdx;
}

void	go_up(t_opt *opt)
{
	if (opt->map[(int)((opt->y + opt->pdy) / MAPSQUARE)][(int)((opt->x + opt->pdx) / MAPSQUARE)] == '1')
		return;
	opt->x += opt->pdx;
	opt->y += opt->pdy;
}

void	go_down(t_opt *opt)
{
	if (opt->map[(int)((opt->y - opt->pdy) / MAPSQUARE)][(int)((opt->x - opt->pdx) / MAPSQUARE)] == '1')
		return;
	opt->x -= opt->pdx;
	opt->y -= opt->pdy;
}
