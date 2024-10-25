/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:04 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/25 14:47:15 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
}

void	ft_init_all(t_parsing *s_parse, t_infomap *s_infos)
{
	ft_init_parsing(s_parse);
	ft_init_map(s_infos);
}
