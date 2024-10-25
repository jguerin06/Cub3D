/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:07:24 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/25 18:03:04 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_error(t_parsing *s_parse)
{
	if (s_parse->north != 1 || s_parse->south != 1 || s_parse->west != 1
		|| s_parse->east != 1 || s_parse->floor != 1 || s_parse->ceiling != 1
		|| s_parse->map_wg_char != 0 || s_parse->map_end != 0
		|| s_parse-> map_wall != 0 || s_parse->map_dup != 0
		|| s_parse->map_no_pos != 0 || s_parse->no_map != 0)
		return (1);
	return (0);
}

void	ft_get_error(t_parsing *s_parse, char **tab, int i)
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
		i++;
	}
}

static int	ft_print_error(int error, t_parsing *s_parse)
{
	if (error == 0 && (s_parse->north == 2
			|| s_parse->south == 2 || s_parse->west == 2 || s_parse->east == 2
			|| s_parse->floor == 2 || s_parse->ceiling == 2))
		return (err_msg(NULL, "Dup in map", ERROR));
	//ft_print_wrong_text(s_parse, error);
	if (ft_print_error_map(s_parse, error) == -1)
		return (ERROR);
	return (0);
}

int	ft_check_parsing(t_parsing *pars, t_infomap *map, int error)
{
	char		**values;
	char		**mapp;

	values = (char **)malloc(sizeof(char *) * 7);
	if (!values)
		return (ERROR);
	ft_get_error(pars, map->map, 0);
	values = ft_fill_values(map->map, pars, values, 0);
	mapp = ft_fill_map(map->truemap);
	(void)error;
	ft_clear_tab(mapp);
	ft_check_map(map->truemap, pars, 0, 0);
	if (ft_print_error(error, pars) == ERROR)
		return (ERROR);
	ft_clear_tab(values);
	if (ft_error(pars) == 1)
		return (1);
	return (0);
}

/*	printf("======= Keybinds ======\n");
	printf("WASD: Move around\n");
	printf("Arrow keys: Turn around\n");
	printf("M: Show mouse cursor\n");
	printf("N: Hide mouse cursor\n");
	printf("Scroll: Change weapon\n");
	printf("ESC: Exit\n");
	printf("=======================\n");*/
