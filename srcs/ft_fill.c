/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:01:07 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/15 15:16:25 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_fill_values(char **tab, t_struct *s_parse, char **values, int i)
{
	int	j;

	j = 0;
	while (tab[i])
	{
		if (ft_get_element(tab[i]) == 1 && s_parse->north == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 2 && s_parse->south == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 3 && s_parse->east == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 4 && s_parse->west == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 5 && s_parse->floor == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 6 && s_parse->ceiling == 1)
			values[j++] = ft_strdup(tab[i]);
		i++;
	}
	values[j] = 0;
	return (values);
}

char	**ft_fill_map(char **tab)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char *) * 50);
	if (!map)
		return (NULL);
	while (tab && tab[i])
	{
		if (ft_space_before(tab[i]) == 1)
		{
			while (tab[i])
				map[j++] = ft_strdup(tab[i++]);
			break ;
		}
		i++;
	}
	map[j] = 0;
	return (map);
}

t_struct2	*ft_fill_info(t_struct2 *s_infos, char **tab, int i)
{
	while (tab && tab[i])
	{
		if (ft_get_element(tab[i]) == 1)
			s_infos->north = ft_strdup(tab[i] + 3);
		if (ft_get_element(tab[i]) == 2)
			s_infos->south = ft_strdup(tab[i] + 3);
		if (ft_get_element(tab[i]) == 3)
			s_infos->east = ft_strdup(tab[i] + 3);
		if (ft_get_element(tab[i]) == 4)
			s_infos->west = ft_strdup(tab[i] + 3);
		if (ft_get_element(tab[i]) == 5)
			s_infos->floor = ft_strdup(tab[i] + 2);
		if (ft_get_element(tab[i]) == 6)
			s_infos->ceiling = ft_strdup(tab[i] + 2);
		i++;
	}
	s_infos->map = ft_fill_map(tab);
	return (s_infos);
}
