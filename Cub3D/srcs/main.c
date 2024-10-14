/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:53:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/14 13:26:28 by jguerin          ###   ########.fr       */
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

	if (argc != 2)
		return (err_msg("Usage", ERR_USAGE, ERROR));
	ft_init_all(&parsing, &map);
	error = check_arg(argv[1], true);
	ft_check_parsing(tab, error); // fonctionne pas
	map.y = ft_check_file(argv[1], 0);
	copy_file(argv[1], &map);
	for (int i = 0; map.map[i]; i++)
		printf("%s", map.map[i]);
	printf("%d\n", error);
	return (0);
}

// check_parsing attend un char ** (tab) mais c'est un
// char * (argv[1]) qui contient les donnees de la map
// jsp comment faire ... :(
