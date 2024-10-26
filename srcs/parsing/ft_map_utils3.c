/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:44:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/26 15:47:07 by jguerin          ###   ########.fr       */
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

int	ft_other_char(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_diff(char c)
{
	if (c != '\0' && c != '0' && c != '1' && c != '2' && c != ' ' && c != '\n')
		return (1);
	return (0);
}
