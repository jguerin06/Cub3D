/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:49:28 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/27 10:50:54 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	go_up(t_opt *opt)
{
	if (opt->map[(int)((opt->y + opt->pdy) / MAPSQUARE)][(int)
	((opt->x + opt->pdx) / MAPSQUARE)] == '1')
		return ;
	opt->x += opt->pdx;
	opt->y += opt->pdy;
}

void	go_down(t_opt *opt)
{
	if (opt->map[(int)((opt->y - opt->pdy) / MAPSQUARE)][(int)
	((opt->x - opt->pdx) / MAPSQUARE)] == '1')
		return ;
	opt->x -= opt->pdx;
	opt->y -= opt->pdy;
}
