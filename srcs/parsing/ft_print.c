/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:57:32 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/26 15:14:23 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	ft_print_error_map(t_parsing *s_parse, int error)
{
	if (error == 0 && s_parse->map_wall == 1)
		return (err_msg(NULL, ERR_MAP_NO_WALLS, ERROR));
	if (error == 0 && s_parse->map_wg_char == 1)
		return (err_msg(NULL, ERR_INV_LETTER, ERROR));
	if (error == 0 && s_parse->map_end == 1)
		return (err_msg(NULL, ERR_MAP_LAST, ERROR));
	if (error == 0 && s_parse->map_dup == 1)
		return (err_msg(NULL, ERR_NUM_PLAYER, ERROR));
	if (error == 0 && s_parse->map_no_pos == 1)
		return (err_msg(NULL, ERR_PLAYER_DIR, ERROR));
	return (0);
}
