/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:57:32 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/22 12:08:14 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_print_error_map(t_parsing *s_parse, int error)
{
	if (error == 0 && s_parse->map_wall == 1)
		ft_putstr_fd("Warning: The map is not surrounded by walls\n", 2);
	if (error == 0 && s_parse->map_wg_char == 1)
		ft_putstr_fd("Warning: Wrong charac have been found in the map\n", 2);
	if (error == 0 && s_parse->map_end == 1)
		ft_putstr_fd("Warning: The map is not at the end of the file\n", 2);
	if (error == 0 && s_parse->map_dup == 1)
		ft_putstr_fd("Warning: Too much pos have been found in the map\n", 2);
	if (error == 0 && s_parse->map_no_pos == 1)
		ft_putstr_fd("Warning: No position have been found in the map\n", 2);
}

void	ft_print_no_values(t_parsing *s_parse, int error)
{
	if (error == 0 && s_parse->north == 0)
		ft_putstr_fd("Warning: no north texture\n", 2);
	if (error == 0 && s_parse->south == 0)
		ft_putstr_fd("Warning: no south texture\n", 2);
	if (error == 0 && s_parse->east == 0)
		ft_putstr_fd("Warning: no east texture\n", 2);
	if (error == 0 && s_parse->west == 0)
		ft_putstr_fd("Warning: no west texture\n", 2);
	if (error == 0 && s_parse->floor == 0)
		ft_putstr_fd("Warning: no floor texture\n", 2);
	if (error == 0 && s_parse->ceiling == 0)
		ft_putstr_fd("Warning: no ceiling texture\n", 2);
	if (error == 0 && s_parse->no_map == 1)
		ft_putstr_fd("Warning: no map\n", 2);
}

void	ft_print_wrong_text(t_parsing *s_parse, int error)
{
	if (error == 0 && s_parse->north == 3)
		ft_putstr_fd("Warning: Wrong north texture file\n", 2);
	if (error == 0 && s_parse->south == 3)
		ft_putstr_fd("Warning: Wrong south texture file\n", 2);
	if (error == 0 && s_parse->west == 3)
		ft_putstr_fd("Warning: Wrong west texture file\n", 2);
	if (error == 0 && s_parse->east == 3)
		ft_putstr_fd("Warning: Wrong east texture file\n", 2);
}
