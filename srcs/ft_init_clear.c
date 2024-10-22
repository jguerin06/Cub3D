/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:48:21 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/22 15:45:10 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_parsing	*ft_init_parsing(t_parsing *s_parse)
{
	s_parse->north = 0;
	s_parse->south = 0;
	s_parse->east = 0;
	s_parse->west = 0;
	s_parse->floor = 0;
	s_parse->ceiling = 0;
	s_parse->wrong_line = 0;
	s_parse->map_wg_char = 0;
	s_parse->map_end = 0;
	s_parse->map_wall = 0;
	s_parse->map_dup = 0;
	s_parse->map_no_pos = 0;
	s_parse->no_map = 0;
	return (s_parse);
}

t_infomap	*ft_init_map(t_infomap *s_infos)
{
	s_infos->x = 0;
	s_infos->y = 0;
	s_infos->start_of_map = -1;
	s_infos->end_of_map = -1;
	s_infos->map_line = 0;
	s_infos->north = NULL;
	s_infos->south = NULL;
	s_infos->east = NULL;
	s_infos->west = NULL;
	s_infos->floor = NULL;
	s_infos->ceiling = NULL;
	s_infos->ceiling_color = NULL;
	s_infos->floor_color = NULL;
	s_infos->map = NULL;
	s_infos->truemap = NULL;
	s_infos->text_no = NULL;
	s_infos->text_so = NULL;
	s_infos->text_ea = NULL;
	s_infos->text_we = NULL;

	return (s_infos);
}

void	ft_clear_struct2(t_infomap *map)
{
	if (map->ceiling)
		ft_clear_tab(map->ceiling);
	if (map->floor)
		ft_clear_tab(map->floor);
	if (map->map)
		ft_clear_tab(map->map);
	if (map->truemap)
		ft_clear_tab(map->truemap);
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->east)
		free(map->east);
	if (map->west)
		free(map->west);
	if (map->ceiling_color)
		free(map->ceiling_color);
	if (map->floor_color)
		free(map->floor_color);
	if (map->text_no)
		mlx_delete_texture(map->text_no);
	if (map->text_so)
		mlx_delete_texture(map->text_so);
	if (map->text_ea)
		mlx_delete_texture(map->text_ea);
	if (map->text_we)
		mlx_delete_texture(map->text_we);
}
