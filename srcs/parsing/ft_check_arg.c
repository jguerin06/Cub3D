/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:40:11 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/26 11:15:49 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_is_cub(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 6)
		return (err_msg(NULL, FILE_NOT_CUB, ERROR));
	if (file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (0);
	return (-1);
}

static int	ft_is_png(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] == '.' && file[i - 3] == 'p'
		&& file[i - 2] == 'n' && file[i - 1] == 'g')
		return (0);
	return (-1);
}

static int	ft_is_dir(char *file)
{
	int	fd;

	fd = 0;
	fd = open(file, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (-1);
	}
	return (0);
}

int	check_arg(char *file)
{
	int	fd;

	if (ft_is_dir(file) == -1)
		return (err_msg(file, ERR_FILE_IS_DIR, ERROR));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(file, ERR_INVALID_FILE, ERROR));
	close(fd);
	if (ft_is_cub(file) == -1)
		return (err_msg(file, FILE_NOT_CUB, ERROR));
	return (SUCCESS);
}

int	check_texture(t_infomap *map)
{
	if (ft_is_png(map->north) == -1)
		return (err_msg(map->north, ERR_FILE_NOT_PNG, ERROR));
	if (ft_is_png(map->south) == -1)
		return (err_msg(map->south, ERR_FILE_NOT_PNG, ERROR));
	if (ft_is_png(map->east) == -1)
		return (err_msg(map->east, ERR_FILE_NOT_PNG, ERROR));
	if (ft_is_png(map->west) == -1)
		return (err_msg(map->west, ERR_FILE_NOT_PNG, ERROR));
	return (SUCCESS);
}
