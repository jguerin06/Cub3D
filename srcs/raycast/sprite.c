/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 04:46:53 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/27 11:39:14 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_knife(t_opt *opt)
{
	mlx_texture_t	*weapon;

	weapon = mlx_load_png("./textures/knife/0.png");
	opt->weapon_img = mlx_texture_to_image(opt->mlx, weapon);
	mlx_delete_texture(weapon);
	mlx_resize_image(opt->weapon_img, 2700, 1100);
	mlx_image_to_window(opt->mlx, opt->weapon_img, 0, 0);
	opt->weapon_img->instances[0].x = WIDTH / 2 - (2700 / 2);
	opt->weapon_img->instances[0].y = HEIGHT - 1100;
	opt->weapon_img->instances[0].z = 6;
}

void	draw_pickaxe(t_opt *opt)
{
	mlx_texture_t	*weapon;

	weapon = mlx_load_png("./textures/pickaxe.png");
	opt->weapon_img = mlx_texture_to_image(opt->mlx, weapon);
	mlx_delete_texture(weapon);
	mlx_resize_image(opt->weapon_img, 2700, 1100);
	mlx_image_to_window(opt->mlx, opt->weapon_img, 0, 0);
	opt->weapon_img->instances[0].x = WIDTH / 2 - 500;
	opt->weapon_img->instances[0].y = HEIGHT - 1100;
	opt->weapon_img->instances[0].z = 6;
}

void	draw_weapon(t_opt *opt, int weapon)
{
	if (opt->animation_active)
		return ;
	if (opt->weapon_img)
		mlx_delete_image(opt->mlx, opt->weapon_img);
	if (weapon == 0 && opt->weapon_img)
		mlx_delete_image(opt->mlx, opt->weapon_img);
	else if (weapon == 1)
		draw_knife(opt);
	else if (weapon == 2)
		draw_pickaxe(opt);
}
