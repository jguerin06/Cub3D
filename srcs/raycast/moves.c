/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:00:04 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/27 10:50:38 by jguerin          ###   ########.fr       */
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
	if (opt->map[(int)((opt->y + opt->pdx) / MAPSQUARE)][(int)
	((opt->x - opt->pdy) / MAPSQUARE)] == '1')
		return ;
	opt->x -= opt->pdy;
	opt->y += opt->pdx;
}

void	go_left(t_opt *opt)
{
	if (opt->map[(int)((opt->y - opt->pdx) / MAPSQUARE)][(int)
	((opt->x + opt->pdy) / MAPSQUARE)] == '1')
		return ;
	opt->x += opt->pdy;
	opt->y -= opt->pdx;
}
