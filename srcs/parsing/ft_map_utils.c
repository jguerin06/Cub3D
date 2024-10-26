/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:13:26 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/26 15:47:52 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_zero_oob(char *s1, char *s, char *s2)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	while (s && s[i] != '0' && i > 0)
		i--;
	if (i >= ft_strlenn(s1))
		return (1);
	if (i >= ft_strlenn(s2))
		return (1);
	return (0);
}

// le 2 c'est pour le bonus

int	size_of_map(t_infomap *map)
{
	int	i;
	int	big_len;

	i = 0;
	big_len = ft_strlenn(map->truemap[i]) - 1;
	while (map->truemap[i])
	{
		if (ft_strlenn(map->truemap[i]) > big_len)
			big_len = ft_strlenn(map->truemap[i]) - 1;
		if (big_len > MAX_WIDTH)
			return (err_msg(NULL, ERR_MAP_TOO_LARGE, ERROR));
		i++;
		if (i > MAX_HEIGHT)
			return (err_msg(NULL, ERR_MAP_TOO_LONG, ERROR));
	}
	map->width = big_len;
	map->height = i;
	return (SUCCESS);
}

int	count_map_lines(t_infomap *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] == ' ' || map->map[i][j] == '\t'
			|| map->map[i][j] == '\r' || map->map[i][j] == '\v'
			|| map->map[i][j] == '\f')
			j++;
		if (map->map[i][j] == '1')
		{
			if (map->start_of_map == -1)
				map->start_of_map = i;
			map->end_of_map = i;
		}
		i++;
	}
	if (map->start_of_map == -1)
		return (err_msg(NULL, ERR_MAP_NO_WALLS, ERROR));
	map->map_line = map->end_of_map - map->start_of_map + 1;
	return (SUCCESS);
}
