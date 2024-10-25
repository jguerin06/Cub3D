/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:13:26 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/24 07:05:52 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_element(char *str)
{
	int	i;

	i = 0;
	if (str && str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			return (1);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (2);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (3);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (4);
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (5);
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (6);
		else if (ft_is_diff(str[i]) == 1)
			return (7);
	}
	return (0);
}

int	ft_is_pos(char *str)
{
	int	i;
	int	dup;

	i = 0;
	dup = 0;
	while (str && str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			dup++;
		i++;
	}
	return (dup);
}

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

int	ft_is_diff(char c)
{
	if (c != '\0' && c != '0' && c != '1' && c != '2' && c != ' ' && c != '\n')
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
			return (err_msg(NULL, ERR_MAP_TOO_LARGE, 0), ERROR);
		i++;
		if (i > MAX_HEIGHT)
			return (err_msg(NULL, ERR_MAP_TOO_LONG, 0), ERROR);
	}
	map->width = big_len;
	map->height = i;
	return (SUCCESS);
}
