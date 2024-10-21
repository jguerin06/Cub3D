/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:13:26 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/21 15:59:39 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_is_pos(char *str)
{
	int	i;
	int	j;
	int	dup;

	i = 0;
	dup = 0;
	while (str && str[i])
	{
		j = 0;
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			dup++;
		j++;
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

int	size_of_map(t_struct2 *map)
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
	return (SUCCESS);
}
