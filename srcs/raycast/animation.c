/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:10:46 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/27 02:29:11 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static mlx_texture_t	*knife_frame(t_opt *opt, int i)
{
	mlx_texture_t	*texture;
	char			*path;
	char			*path2;

	path = ft_itoa(i);
	path2 = ft_strjoin_nf("./textures/knife/", path);
	free(path);
	path = ft_strjoin_nf(path2, ".png");
	texture = mlx_load_png(path);
	free(path2);
	free(path);
	if (i == opt->total_frames - 1)
		opt->animation_active = 0;
	return (texture);
}

void	animate_knife(t_opt *opt)
{
	static int		anim = 0;
	static int		time = 0;
	mlx_texture_t	*text;

	while (anim != 0 && ++time < 1)
		return ;
	if (opt->weapon_img)
		mlx_delete_image(opt->mlx, opt->weapon_img);
	mlx_set_window_title(opt->mlx, "🔪 CS:GO 🔪");
	text = knife_frame(opt, anim);
	anim++;
	if (anim == opt->total_frames)
	{
		mlx_set_window_title(opt->mlx, NAME);
		anim = 0;
	}
	time = 0;
	opt->weapon_img = mlx_texture_to_image(opt->mlx, text);
	mlx_resize_image(opt->weapon_img, 2700, 1100);
	mlx_image_to_window(opt->mlx, opt->weapon_img, 0, 0);
	opt->weapon_img->instances[0].x = WIDTH / 2 - (2700 / 2);
	opt->weapon_img->instances[0].y = HEIGHT - 1100;
	mlx_delete_texture(text);
}
