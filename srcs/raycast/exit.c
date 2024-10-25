/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:53:32 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/25 15:15:35 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_img(t_opt *opt)
{
	if (opt->plr_img)
		mlx_delete_image(opt->mlx, opt->plr_img);
	if (opt->map_img)
		mlx_delete_image(opt->mlx, opt->map_img);
	if (opt->ray_img)
		mlx_delete_image(opt->mlx, opt->ray_img);
	if (opt->celling_img)
		mlx_delete_image(opt->mlx, opt->celling_img);
	if (opt->floor_img)
		mlx_delete_image(opt->mlx, opt->floor_img);
	if (opt->wall_img)
		mlx_delete_image(opt->mlx, opt->wall_img);
	if (opt->weapon_img)
		mlx_delete_image(opt->mlx, opt->weapon_img);
}

void	exit_cub(t_opt *opt)
{	
	ft_clear_tab(opt->map);
	free_img(opt);
	mlx_close_window(opt->mlx);
	mlx_terminate(opt->mlx);
	exit(EXIT_SUCCESS);
}
