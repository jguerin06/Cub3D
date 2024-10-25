/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:40:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/22 16:38:31 by lforgion         ###   ########.fr       */
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
