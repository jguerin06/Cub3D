/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:53:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/09/19 13:49:04 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;

	while(argc != 2)
	{
		printf("Mauvaise utilisation : [exe] [map]\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		{
			printf("Fichier non existant\n");
			return (1);
		}
	else if (ft_is_cub(argv[1]) == 1)
		{
			printf("Mauvaise extension de fichier\n");
			return (1);
		}
	return (0);
}
