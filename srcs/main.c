/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:53:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/16 11:23:09 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_struct	parsing;
	t_struct2	map;
	char		**tab;
	int			error;
	int 		test;

	if (argc != 2)
		return (err_msg("Usage", ERR_USAGE, ERROR));
	ft_init_all(&parsing, &map);
	error = check_arg(argv[1], true);
	map.y = ft_check_file(argv[1], 0);
	tab = copy_file(argv[1], map.y);
	test = count_map_lines(tab); // test
	ft_check_parsing(tab, error);
	for (int i = 0; tab[i]; i++)
		printf("%s", tab[i]);
	printf("%d\n", error);
	printf("longueur map : %d\n", test);
	return (0);
}


/*
int	main(int argc, char **argv)
{
	t_struct	parsing;
	t_struct2	map;
	char		**tab;
	int			error;

	if (argc != 2)
		return (err_msg("Usage", ERR_USAGE, ERROR));
	ft_init_all(&parsing, &map);
	error = check_arg(argv[1], true);
	map.y = ft_check_file(argv[1], 0);
	tab = copy_file(argv[1], map.y);
	ft_check_parsing(tab, error);
	for (int i = 0; tab[i]; i++)
		printf("%s", tab[i]);
	printf("%d\n", error);
	return (0);
}
*/
