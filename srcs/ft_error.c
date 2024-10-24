/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:49:15 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/22 16:10:59 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
// marwen tu feuxra 1 truque ( : )

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

int	ft_double(int i)
{
	if (i == 1 || i == 2)
		return (2);
	return (1);
}

int	map_wall(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && (str[i] == ' ' || str[i] == '1'))
		i++;
	if (str && (str[i] == '\0' || str[i] == '\n'))
		return (0);
	return (1);
}

int	wall_around(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && str[i] != '1')
		return (1);
	while (str && str[i])
		i++;
	while (i > 0 && str[i - 1] == ' ')
		i--;
	if (str && str[i - 1] != '1')
		return (0);
	return (1);
}
/*
static int check_corner(char **map, int i, int j)
{
    if (map[i][j] == '0')
    {
        if ((map[i + 1][j + 1] == '\n') || (map[i - 1][j - 1] == '\n') || (map[i - 1][j + 1] == '\n') || (map[i + 1][j - 1] == '\n'))
            return (-1);
        if ((map[i + 1][j + 1] == ' ') || (map[i - 1][j - 1] == ' ') || (map[i - 1][j + 1] == ' ') || (map[i + 1][j - 1] == ' '))
            return (-1);
    }   
    return (0);
}*/

int	err_msg(char *arg, char *error, int code)
{
	ft_putstr_fd("cub3D: Error", 2);
	if (arg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
	}
	if (error)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error, 2);
	}
	return (code);
}
