/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:27:14 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/22 11:36:55 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_commas(char *color)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (color[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static int	is_color(char **color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (color[j])
	{
		if (ft_strlen(color[j]) < 1 || ft_strlen(color[j]) > 3)
			return (ERROR);
		while (color[j][i])
		{
			if (color[j][i] < '0' || color[j][i] > '9')
				return (err_msg("Usage", ERR_INVALID_COLOR, ERROR), ERROR);
			i++;
		}
		if (ft_atoi(color[j]) > 255)
			return (err_msg("Usage", ERR_RGB_VAL, ERROR), ERROR);
		j++;
		i = 0;
	}
	return (SUCCESS);
}

char	**get_color(char *line, int i)
{
	char	**color;
	char	**tab;

	color = NULL;
	tab = ft_split(line, ' ');
	if (tab && ft_sstrlen(tab) != 2)
		return (err_msg("Usage", ERR_RGB_VAL, ERROR), NULL);
	color = ft_split(tab[1], ',');
	if (!color || count_commas(tab[1]) != 2 || ft_sstrlen(color) != 3)
		return (err_msg("Usage", ERR_RGB_VAL, ERROR), NULL);
	while (color[2][++i])
		if (color[2][i] == '\n')
			color[2][i] = '\0';
	if (is_color(color) == ERROR)
	{
		tab = ft_clear_tab(tab);
		return (err_msg("Usage", ERR_RGB_VAL, ERROR), NULL);
	}
	tab = ft_clear_tab(tab);
	return (color);
}

int	*convert_color(char **color)
{
	int	i;
	int	j;
	int	*conv;

	i = 0;
	j = 0;
	while (color[i])
		i++;
	conv = malloc(sizeof(int) * (i + 1));
	if (!conv)
		return (NULL);
	while (color[j])
	{
		conv[j] = ft_atoi(color[j]);
		j++;
	}
	conv[j] = 0;
	return (conv);
}

// changer les msg d'erreurs
