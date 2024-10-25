/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:53:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/25 15:21:23 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	copy_map(t_infomap *map)
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

static int	tmax(char *path, t_parsing *pars, t_infomap *map)
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

static int	check_info(t_infomap *map)
{
	if (!map->north || !map->east || !map->west || !map->south)
		return (err_msg(NULL, ERR_TEXTURE_MISS, ERROR));
	if (!map->ceiling || !map->floor)
		return (err_msg(NULL, ERR_INVALID_COLOR, ERROR));
	if (check_texture(map) == -1)
		return (ERROR);
	map->floor_color = convert_color(map->floor);
	map->ceiling_color = convert_color(map->ceiling);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_parsing	parsing;
	t_infomap	map;
	int			error;

	if (argc != 2)
		return (err_msg("Usage", ERR_USAGE, ERROR));
	ft_init_all(&parsing, &map);
	error = check_arg(argv[1]);
	if (error == ERROR || tmax(argv[1], &parsing, &map) == ERROR)
		return (ft_clear_struct2(&map), -1);
	ft_fill_info(&map, map.map);
	if (check_info(&map) == ERROR)
		return (ft_clear_struct2(&map), ERROR);
	load_texture(&map);
	size_of_map(&map);
	error = ft_check_parsing(&parsing, &map, error);
	start_raycast(map);
	ft_clear_struct2(&map);
	return (SUCCESS);
}
