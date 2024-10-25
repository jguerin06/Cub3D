/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:36:09 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/25 14:23:19 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	while (str && str[i] && str[i + 1])
		i++;
	while (i > 0 && str[i - 1] == ' ')
		i--;
	if (str && str[i - 1] != '1')
		return (1);
	return (0);
}

int	check_corner(char **map, int i, int j)
{
	if (map[i][j] == '0')
	{
		if ((map[i + 1][j + 1] == '\n') || (map[i - 1][j - 1] == '\n')
			|| (map[i - 1][j + 1] == '\n') || (map[i + 1][j - 1] == '\n'))
			return (-1);
		if ((map[i + 1][j + 1] == ' ') || (map[i - 1][j - 1] == ' ')
			|| (map[i - 1][j + 1] == ' ') || (map[i + 1][j - 1] == ' '))
			{
				printf("pas de coin\n");
				return (-1);
			}
	}
	return (0);
}

int	player_position(t_infomap *map, t_opt *player)
{
	int		x;
	int		y;
	
	y = 0;
	while (map->truemap && map->truemap[y])
	{
		x = 0;
		while (map->truemap[y][x])
		{
			if (map->truemap[y][x] == 'N' || map->truemap[y][x] == 'S'
				|| map->truemap[y][x] == 'E' || map->truemap[y][x] == 'W')
			{
				player->direction = map->truemap[y][x];
				player->pos_x = x + 1;
				player->pos_y = y + 1;
				return (SUCCESS);
			}
			x++;
		}
		y++;
	}
	return (ERROR);
}
