/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:53:10 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/18 14:20:55 by jguerin          ###   ########.fr       */
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
			&& str[i] != ' ' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	count_map_lines(t_struct2 *map)
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
		return (ERROR);
	map->map_line = map->end_of_map - map->start_of_map + 1;
	return (SUCCESS);
}

static void ft_check_map2(t_struct *s_parse, int dup, char *str)
{
	if (dup > 1)
		s_parse->map_dup = 1;
	if (dup == 0)
		s_parse->map_no_pos = 1;
	if (str != 0)
		s_parse->map_end = 1;
}

void ft_check_map(char **map, t_struct *s_parse, int i, int dup)
{
	if (map[0] == 0)
		s_parse->no_map = 1;
	else
	{
		while (map && map[i])
		{
			if ((i == 0 && map_wall(map[i]) == 1) || wall_around(map[i]) == 1)
			{
				s_parse->map_wall = 1;
				printf("a la ligne %d\n", i);
			}

			if (map[i + 1] == 0)
				if (map_wall(map[i]) == 1)
				{
					s_parse->map_wall = 1;
					//printf("probleme de mur derniere ligne\n");
				}
			if (i > 0 && map[i + 1] != 0 && ft_zero_oob(map[i - 1], map[i], map[i + 1]) == 1)
			{
				s_parse->map_wall = 1;
				//printf("Problème avec des zeros hors des murs à la ligne %d\n", i);
			}

			if (ft_other_char(map[i]) == 1)
			{
				s_parse->map_wg_char = 1;
				//printf("Caractères invalides trouvés à la ligne %d\n", i);
			}
			if (ft_is_pos(map[i]) > 0)
				dup = dup + ft_is_pos(map[i]);
			i++;
		}
		ft_check_map2(s_parse, dup, map[i]);
	}
}

/* 

	2 int, 1 au debut de la map et 1 a la fin

	x: celui d'en haut descend jusqua voir un '1' donc tab[x]
		-> commencement de la copie
	y: comme x mais a l'envers

	du coup malloc ((y - x) + 1) == taille de map
	truemap copie: x le debut et il fini a y - x

*/

/*static int hollow(char **tab, int *j)
{
	int	size;

	size = 0;
	while (tab[*j])
	{
		while (tab[*j])
		{
			
		}
		*j++;
	}
	return (0);
}
*/
