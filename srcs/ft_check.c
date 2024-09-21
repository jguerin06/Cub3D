/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:40:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/09/21 12:53:03 by jguerin          ###   ########.fr       */
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
	return (1);
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
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(line);
		countLine++;
	}
	close(fd);
	return (countLine); // s_infos y = countLine
}

int	copy_file(char *str, t_struct2 *s_infos)
{
	int i;
	int fd;

	i = 0;
	s_infos->map = malloc(sizeof(char *) * (s_infos->y + 1));
	if (s_infos->map == NULL)
		return(-1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		return (-1);
	}
	while(1)
	{
		s_infos->map[i] = get_next_line(fd);
		if (s_infos->map[i] == NULL)
			break;
		i++;
	}
	close(fd);
	return (0);
}
