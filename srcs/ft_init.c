/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:48:21 by jguerin           #+#    #+#             */
/*   Updated: 2024/09/19 11:10:11 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_struct	*ft_init_struct(t_struct *s_parse)
{
	s_parse->north = 0;
	s_parse->south = 0;
	s_parse->east = 0;
	s_parse->west = 0;
	s_parse->sprite = 0;
	s_parse->floor = 0;
	s_parse->ceiling = 0;
	s_parse->map_wg_char = 0;
	s_parse->map_end = 0;
	s_parse->map_wall = 0;
	s_parse-> map_dup = 0;
	s_parse->map_no_pos = 0;
	s_parse->no_map = 0;
	return(s_parse);
}
