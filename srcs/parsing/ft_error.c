/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:49:15 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/23 10:38:28 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// marwen tu feuxra 1 truque ( : )

int	ft_double(int i)
{
	if (i == 1 || i == 2)
		return (2);
	return (1);
}

int	err_msg(char *arg, char *error, int code)
{
	ft_putstr_fd("cub3D: Error", 2);
	if (arg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
	}
	if (error)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error, 2);
	}
	return (code);
}
