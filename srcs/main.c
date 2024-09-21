/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:53:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/09/21 12:56:05 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			fd;
	t_struct	parsing;
	t_struct2	map;

	if(argc != 2)
	{
		printf("Mauvaise utilisation : [exe] [map]\n");
		return (1);
	}
	ft_init_struct(&parsing, &map);
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
	map.y = ft_check_file(argv[1], 0);
	printf("%d\n", map.y);
	copy_file(argv[1], &map);
	for (int i = 0; map.map[i]; i++)
		printf("%s", map.map[i]);
	return (0);
}
