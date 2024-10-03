/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:07:24 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/03 13:24:09 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_error(t_struct *s_parse)
{
	if (s_parse->north != 1 || s_parse->south != 1 || s_parse->west != 1 ||
	s_parse->east != 1 || s_parse->floor != 1 || s_parse->ceiling != 1 || 
	s_parse->map_wg_char != 0 || s_parse->map_end != 0 || 
	s_parse-> map_wall != 0 || s_parse->map_dup != 0 || 
	s_parse->map_no_pos != 0 || s_parse->no_map != 0)
		return (1);
	return (0);
}

t_struct	*ft_get_error(t_struct *s_parse, char **tab, int i)
{
	while (tab[i])
	{
		if (ft_get_element(tab[i]) == 1)
			s_parse->north = ft_double(s_parse->north);
		else if (ft_get_element(tab[i]) == 2)
			s_parse->south = ft_double(s_parse->south);
		else if (ft_get_element(tab[i]) == 3)
			s_parse->east = ft_double(s_parse->east);
		else if (ft_get_element(tab[i]) == 4)
			s_parse->west = ft_double(s_parse->west);
		else if (ft_get_element(tab[i]) == 5)
			s_parse->floor = ft_double(s_parse->floor);
		else if (ft_get_element(tab[i]) == 6)
			s_parse->ceiling = ft_double(s_parse->ceiling);
		else if (ft_get_element(tab[i]) == 7)
			s_parse->wrong_line = 1;
		i++;
	}
	return (s_parse);
}

int	ft_check_parsing(char **tab, int error)
{
	char		**values;
	char		**map;
	t_struct	*s_parse;

	if (!(s_parse = malloc(sizeof(t_struct))))
		return (-1);
	if (!(values = (char **)malloc(sizeof(char *) * 9)))
		return (-1);
	s_parse = ft_init_struct(s_parse);
	s_parse = ft_get_error(s_parse,tab , 0);
	values = ft_fill_values(tab, s_parse, values, 0);
}
