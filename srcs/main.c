/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:53:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/21 16:12:11 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

static int	copy_map(t_struct2 *map)
{
	int	i;
	int	j;

	i = 0;
	j = map->start_of_map;
	map->truemap = malloc(sizeof(char *) * (map->map_line + 1));
	if (map->truemap == NULL)
		return (ERROR);
	while (map->map[j] && j <= map->end_of_map)
		map->truemap[i++] = ft_strdup(map->map[j++]);
	map->truemap[i] = NULL;
	return (SUCCESS);
}

static int	tmax(char *path, t_struct *pars, t_struct2 *map)
{
	map->y = ft_check_file(path);
	if (map->y == ERROR)
		return (ERROR);
	map->map = copy_file(path, map->y);
	if (map->map == NULL)
		return (ERROR);
	if (count_map_lines(map) == ERROR)
		return (ERROR);
	if (copy_map(map) == ERROR)
		return (ERROR);
	(void)pars;
	return (SUCCESS);
}

static int	check_info(t_struct2 *map)
{
	if (!map->north || !map->east || !map->west || !map->south)
		return (err_msg("Usage", ERR_TEXTURE_MISS, ERROR), ERROR);
	if (!map->ceiling || !map->floor)
		return (err_msg("Usage", ERR_COLOR_MISS, ERROR), ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_struct	parsing;
	t_struct2	map;
	int			error;

	if (argc != 2)
		return (err_msg("Usage", ERR_USAGE, ERROR));
	ft_init_all(&parsing, &map);
	error = check_arg(argv[1]);
	if (tmax(argv[1], &parsing, &map) == ERROR)
		return (ft_clear_struct2(&map), ERROR);
	ft_fill_info(&map, map.map);
	if (check_info(&map) == ERROR)
		return (ft_clear_struct2(&map), ERROR);
	size_of_map(&map);
	ft_check_parsing(&parsing, &map, error);
	return (ft_clear_struct2(&map), SUCCESS);
}

/*
int	main(int argc, char **argv)
{
	t_struct	parsing;
	t_struct2	map;
	char		**tab;
	int			error;

	if (argc != 2)
		return (err_msg("Usage", ERR_USAGE, ERROR));
	ft_init_all(&parsing, &map);
	error = check_arg(argv[1], true);
	map.y = ft_check_file(argv[1], 0);
	tab = copy_file(argv[1], map.y);
	ft_check_parsing(tab, error);
	for (int i = 0; tab[i]; i++)
		printf("%s", tab[i]);
	printf("%d\n", error);
	return (0);
}
*/
