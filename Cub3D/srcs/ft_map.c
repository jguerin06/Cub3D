/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:53:10 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/10 14:04:51 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_other_char(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_space_before(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	if (str[i] == '0' || str[i] == '1' || str[i] == '2')
		return (0);
	return (1);
}
// 2 pour le bonus des portes

t_struct	*ft_check_map2(t_struct *s_parse, int dup, char *str)
{
	if (dup > 1)
		s_parse->map_dup = 1;
	if (dup == 0)
		s_parse->map_no_pos = 1;
	if (str != 0)
		s_parse->map_end = 1;
	return (s_parse);
}

t_struct	*ft_check_map(char **map, t_struct *s_parse, int i, int dup)
{
	if (map[0] == 0)
		s_parse->no_map = 1;
	else
	{
		while (map && map[i] && ft_space_before(map[i]) == 1)
		{
			if ((i == 0 && map_wall(map[i]) == 1) || wall_around(map[i]) == 1)
				s_parse->map_wall = 1;
			if (map[i + 1] == 0)
				if (map_wall(map[i]) == 1)
					s_parse->map_wall = 1;
			if (i > 0 && map[i + 1] != 0
				&& ft_zero_oob(map[i - 1], map[i], map[i + 1]) == 1)
				s_parse->map_wall = 1;
			if (ft_other_char(map[i]) == 1)
				s_parse->map_wg_char = 1;
			if (ft_is_pos(map[i]) > 0)
				dup = dup + ft_is_pos(map[i]);
			i++;
		}
		s_parse = ft_check_map2(s_parse, dup, map[i]);
	}
	return (s_parse);
}
