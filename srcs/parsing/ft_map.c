/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:53:10 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/26 15:50:27 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_walls(char **map, t_parsing *s_parse, int i)
{
	if ((i == 0 && map_wall(map[i]) == 1) || wall_around(map[i]) == 1)
		s_parse->map_wall = 1;
	if (map[i + 1] == 0 && map_wall(map[i]) == 1)
		s_parse->map_wall = 1;
	if (i > 0 && map[i + 1] != 0
		&& ft_zero_oob(map[i - 1], map[i], map[i + 1]) == 1)
		s_parse->map_wall = 1;
}

static void	check_characters(char **map, t_parsing *s_parse, int i, int *dup)
{
	if (ft_other_char(map[i]) == 1)
		s_parse->map_wg_char = 1;
	if (ft_is_pos(map[i]) > 0)
		*dup += ft_is_pos(map[i]);
}

static void	check_corners(char **map, t_parsing *s_parse, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if ((map[i][j] == '0' || map[i][j] == 'N'
			|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			&& check_corner(map, i, j) == -1)
			s_parse->map_wall = 1;
		j++;
	}
}

static void	ft_check_map2(t_parsing *s_parse, int dup, char *str)
{
	if (dup > 1)
		s_parse->map_dup = 1;
	if (dup == 0)
		s_parse->map_no_pos = 1;
	if (str != 0)
		s_parse->map_end = 1;
}

void	ft_check_map(char **map, t_parsing *s_parse, int i, int dup)
{
	if (map[0] == 0)
		s_parse->no_map = 1;
	while (map && map[i])
	{
		check_walls(map, s_parse, i);
		check_characters(map, s_parse, i, &dup);
		check_corners(map, s_parse, i);
		i++;
	}
	ft_check_map2(s_parse, dup, map[i]);
}
