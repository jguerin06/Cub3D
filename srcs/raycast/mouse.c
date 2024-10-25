/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 06:59:35 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/24 07:00:41 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouse_control(t_opt *opt)
{
	if (opt->mouse_visible)
		return;
	mlx_get_mouse_pos(opt->mlx, &(opt->mouse_x), &(opt->mouse_y));
	if (opt->mouse_x < WIDTH / 2)
	{
		opt->pa -= 0.1;
		if (opt->pa < 0)
			opt->pa += 2 * PI;
	}
	else if (opt->mouse_x > WIDTH / 2)
	{
		opt->pa += 0.1;
		if (opt->pa > 2 * PI)
			opt->pa -= 2 * PI;
	}
	if (opt->mouse_x != WIDTH / 2 || opt->mouse_y != HEIGHT / 2)
	{
		opt->pdx = cosf(opt->pa) * 5;
		opt->pdy = sinf(opt->pa) * 5;
		mlx_set_mouse_pos(opt->mlx, WIDTH / 2, HEIGHT / 2);
		opt->mouse_x = WIDTH / 2;
		opt->mouse_y = HEIGHT / 2;
	}
}

void	mouse_visible(t_opt *opt)
{
	opt->mouse_visible = true;
	mlx_set_window_title(opt->mlx, "🐁 Exposed Mouse 🐁");
	mlx_set_cursor_mode(opt->mlx, MLX_MOUSE_NORMAL);
}

void	mouse_hidden(t_opt *opt)
{
	opt->mouse_visible = false;
	mlx_set_window_title(opt->mlx, NAME);
	mlx_set_mouse_pos(opt->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(opt->mlx, MLX_MOUSE_HIDDEN);
}
