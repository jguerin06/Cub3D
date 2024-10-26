/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:40:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/26 16:00:40 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_file(char *str)
{
	int		fd;
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**copy_file(char *str, int y)
{
	int		i;
	int		fd;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (y + 1));
	if (tab == NULL)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (tab);
}

int	load_texture(t_infomap *map)
{
	map->text_no = mlx_load_png(map->north);
	if (!map->text_no)
		return (err_msg(map->north, ERR_TEXTURE_MISS, ERROR));
	map->text_so = mlx_load_png(map->south);
	if (!map->text_so)
		return (err_msg(map->south, ERR_TEXTURE_MISS, ERROR));
	map->text_ea = mlx_load_png(map->east);
	if (!map->text_ea)
		return (err_msg(map->east, ERR_TEXTURE_MISS, ERROR));
	map->text_we = mlx_load_png(map->west);
	if (!map->text_we)
		return (err_msg(map->west, ERR_TEXTURE_MISS, ERROR));
	return (SUCCESS);
}

int	copy_map(t_infomap *map)
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

int	check_info(t_infomap *map)
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
