/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:01:07 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/03 12:34:35 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_fill_values(char **tab, t_struct *s_parse, char **values, int i)
{
	int	j;

	j = 0;
	while(tab[i])
	{
		if (ft_get_element(tab[i]) == 1 && s_parse->north == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 2 && s_parse->south == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 3 && s_parse->east == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 4 && s_parse->west == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 5 && s_parse->floor == 1)
			values[j++] = ft_strdup(tab[i]);
		else if (ft_get_element(tab[i]) == 6 && s_parse->ceiling == 1)
			values[j++] = ft_strdup(tab[i]);
		i++;
	}
	values[j] = 0;
	return (values);
}
