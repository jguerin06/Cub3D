/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:48:21 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/03 13:05:21 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_struct	*ft_init_parsing(t_struct *s_parse)
{
	s_parse->north = 0;
	s_parse->south = 0;
	s_parse->east = 0;
	s_parse->west = 0;
	s_parse->floor = 0;
	s_parse->ceiling = 0;
	s_parse->map_wg_char = 0;
	s_parse->map_end = 0;
	s_parse->map_wall = 0;
	s_parse-> map_dup = 0;
	s_parse->map_no_pos = 0;
	s_parse->no_map = 0;
	return (s_parse);
}

t_struct2	*ft_init_map(t_struct2 *s_infos)
{
	s_infos->x = 0;
	s_infos->y = 0;
	s_infos->north = NULL;
	s_infos->south = NULL;
	s_infos->east = NULL;
	s_infos->west = NULL;
	s_infos->floor = NULL;
	s_infos->ceiling = NULL;
	s_infos->map = NULL;
	s_infos->truemap = NULL;
}
