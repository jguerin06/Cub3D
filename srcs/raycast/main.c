/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 04:47:02 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/25 03:04:13 by lforgion         ###   ########.fr       */
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
}

int	start_raycast(t_infomap	map)
{
	t_opt	*opt;

	opt = malloc(sizeof(t_opt));
	opt->x = 0;
	opt->y = 0;
	if (!(opt->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false)))
	{
		free(opt);
		printf("Error: mlx_init failed\n");
		return(EXIT_FAILURE);
	}
	init_all(opt, map);
	mlx_set_window_limit(opt->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	mlx_set_cursor_mode(opt->mlx, MLX_MOUSE_HIDDEN);
	mlx_scroll_hook(opt->mlx, &scrollhook, opt);;
	mlx_loop_hook(opt->mlx, ft_hook, opt);
	mlx_loop(opt->mlx);
	exit_cub(opt);
	return (EXIT_SUCCESS);
}
