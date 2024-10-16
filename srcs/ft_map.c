/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:53:10 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/16 12:28:26 by jguerin          ###   ########.fr       */
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

int	count_map_lines(char **map)
{
	int	i;
	int	j;
	int	start_of_map;
	int	end_of_map;

	i = 0;
	start_of_map = -1;
	end_of_map = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\r'
			|| map[i][j] == '\v' || map[i][j] == '\f')
			j++;
		if (map[i][j] == '1')
		{
			if (start_of_map == -1)
				start_of_map = i;
			end_of_map = i;
		}
		i++;
	}
	return (end_of_map - start_of_map + 1);
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
			if (i > 0 && map[i + 1] != 0 && ft_zero_oob(map[i - 1], map[i],
					map[i + 1]) == 1)
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
void	get_true_map(char **tab)
{
	int	i;

	i = ft_sstrlen(tab) - 1;
	printf("taille de la map avant check : %d\n", i);
	while (ft_other_char(tab[i]) == 0)
		i--;
	i++;
	printf("taille de la map apres check : %d\n", i);
	while (tab[i])
		printf("%s", tab[i++]);
	exit(0);
	return ;
}

