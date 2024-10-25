/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:21:24 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/24 17:09:32 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void scrollhook(double xdelta, double ydelta, void* param)
{
	t_opt	*opt;

	opt = param;
	(void)xdelta;
	if (ydelta > 0)
		opt->weapon += 1;
	else if (ydelta < 0)
		opt->weapon -= 1;
	if (opt->weapon > 2)
		opt->weapon = 0;
	if (opt->weapon < 0)
		opt->weapon = 2;
	draw_weapon(opt, opt->weapon);
}

static void update_all(t_opt *opt)
{
	opt->plr_img->instances[0].x = opt->x - 7;
	opt->plr_img->instances[0].y = opt->y - 7;
	if (opt->animation_active)
		animate_knife(opt);
	mouse_control(opt);
	draw_ray(opt); // Temporary
	draw_3d(opt);
}

static void	ft_hook_extra(t_opt *opt)
{
	if (mlx_is_key_down(opt->mlx, MLX_KEY_M))
		mouse_visible(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_N))
		mouse_hidden(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_F))
		opt->animation_active = 1;
	update_all(opt);
}

void	ft_hook(void* param)
{
	t_opt	*opt;

	opt = param;
	if (mlx_is_key_down(opt->mlx, MLX_KEY_ESCAPE))
		exit_cub(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_UP) || mlx_is_key_down(opt->mlx, MLX_KEY_W))
		go_up(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_DOWN) || mlx_is_key_down(opt->mlx, MLX_KEY_S))
		go_down(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_A))
		go_left(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_D))
		go_right(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_LEFT))
		turn_left(opt);
	if (mlx_is_key_down(opt->mlx, MLX_KEY_RIGHT))
		turn_right(opt);
	ft_hook_extra(opt);
}
