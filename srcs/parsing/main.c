/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:53:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/26 16:00:29 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_parsing	parsing;
	t_infomap	map;
	int			error;

	if (argc != 2)
		return (err_msg("Usage", ERR_USAGE, ERROR));
	ft_init_all(&parsing, &map);
	error = check_arg(argv[1]);
	if (error == ERROR || map_initializer(argv[1], &parsing, &map) == ERROR)
		return (ft_clear_map(&map), ERROR);
	ft_fill_info(&map, map.map);
	if (check_info(&map) == ERROR || load_texture(&map) == ERROR)
		return (ft_clear_map(&map), ERROR);
	if (ft_check_parsing(&parsing, &map, error) == ERROR
		|| size_of_map(&map) == ERROR)
		return (ft_clear_map(&map), ERROR);
	start_raycast(map);
	ft_clear_map(&map);
	return (SUCCESS);
}
