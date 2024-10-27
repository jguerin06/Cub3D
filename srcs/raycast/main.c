/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 04:47:02 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/27 10:41:59 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_all(t_opt *opt, t_infomap map)
{
	opt->map = ft_sstrdup(map.truemap);
	player_position(&map, opt);
	draw_map(opt, map);
	draw_celling(opt, map);
	draw_floor(opt, map);
	put_player(opt);
	init_knife_animation(opt);
	opt->textures[0] = map.text_no;
	opt->textures[1] = map.text_we;
	opt->textures[2] = map.text_so;
	opt->textures[3] = map.text_ea;
	opt->wall_img = NULL;
	opt->ray_img = NULL;
	opt->weapon_img = NULL;
	opt->mouse_visible = false;
}

int	start_raycast(t_infomap	map)
{
	t_opt	*opt;

	opt = malloc(sizeof(t_opt));
	opt->x = 0;
	opt->y = 0;
	opt->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!(opt->mlx))
	{
		free(opt);
		write(2, "Error: mlx_init failed\n", 23);
		return (EXIT_FAILURE);
	}
	init_all(opt, map);
	mlx_set_window_limit(opt->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	mlx_set_cursor_mode(opt->mlx, MLX_MOUSE_HIDDEN);
	mlx_scroll_hook(opt->mlx, &scrollhook, opt);
	mlx_loop_hook(opt->mlx, ft_hook, opt);
	mlx_loop(opt->mlx);
	exit_cub(opt);
	return (EXIT_SUCCESS);
}
