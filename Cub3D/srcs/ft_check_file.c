/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:40:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/14 12:06:08 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_is_cub(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (0);
	return (-1);
}

int	ft_is_png(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] == '.' && file[i - 3] == 'p'
		&& file[i - 2] == 'n' && file[i - 1] == 'g')
		return (0);
	return (-1);
}

int	ft_is_dir(char *file)
{
	int	fd;

	fd = 0;
	fd = open(file, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	ft_check_file(char *str, int countLine)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		countLine++;
	}
	close(fd);
	return (countLine);
}
// s_infos y = countLine

int	copy_file(char *str, t_struct2 *s_infos)
{
	int	i;
	int	fd;

	i = 0;
	s_infos->map = malloc(sizeof(char *) * (s_infos->y + 1));
	if (s_infos->map == NULL)
		return (-1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		return (-1);
	}
	while (1)
	{
		s_infos->map[i] = get_next_line(fd);
		if (s_infos->map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (0);
}

int	check_arg(char *file, bool cub)
{
	int	fd;

	if (ft_is_dir(file) == -1)
		return (err_msg(file, ERR_FILE_IS_DIR, ERROR));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(file, ERR_INVALID_FILE, 1));
	close(fd);
	if (cub && ft_is_cub(file) == -1)
		return (err_msg(file, ERR_FILE_NOT_CUB, 2));
	if (!cub && ft_is_png(file) == -1)
		return (err_msg(file, ERR_FILE_NOT_PNG, ERROR));
	return (SUCCESS);
}
