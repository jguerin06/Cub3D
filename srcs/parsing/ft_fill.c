/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:01:07 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/25 17:19:50 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**ft_fill_values(char **tab, t_parsing *s_parse, char **values, int i)
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
		while (tab[i])
			map[j++] = ft_strdup(tab[i++]);
		break ;
		i++;
	}
	map[j] = 0;
	return (map);
}

static char	*get_info(char *info)
{
	int		i;
	char	*output;
	char	**all;

	i = -1;
	output = NULL;
	all = ft_split(info, ' ');
	if (!all)
		return (NULL);
	if (ft_sstrlen(all) != 2)
	{
		ft_clear_tab(all);
		return (NULL);
	}
	output = ft_strdup(all[1]);
	while (output[++i])
		if (output[i] == '\n')
			output[i] = '\0';
	ft_clear_tab(all);
	return (output);
}

void	ft_fill_info(t_infomap *s_infos, char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		if (ft_get_element(tab[i]) == 1 && s_infos->north == NULL)
			s_infos->north = get_info(tab[i]);
		if (ft_get_element(tab[i]) == 2 && s_infos->south == NULL)
			s_infos->south = get_info(tab[i]);
		if (ft_get_element(tab[i]) == 3 && s_infos->east == NULL)
			s_infos->east = get_info(tab[i]);
		if (ft_get_element(tab[i]) == 4 && s_infos->west == NULL)
			s_infos->west = get_info(tab[i]);
		if (ft_get_element(tab[i]) == 5 && s_infos->floor == NULL)
			s_infos->floor = get_color(tab[i], -1);
		if (ft_get_element(tab[i]) == 6 && s_infos->ceiling == NULL)
			s_infos->ceiling = get_color(tab[i], -1);
		i++;
	}
}
