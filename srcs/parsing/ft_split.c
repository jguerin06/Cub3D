/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:29:17 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/25 14:12:58 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*free_for_substr(char *str)
{
	free(str);
	return (NULL);
}

static char	*substr_can_free(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free_for_substr(str));
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

static void	*free_everything(char **tab, int w)
{
	int	i;

	i = 0;
	while (i != w)
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	count_word(char const *s, char c)
{
	char	str;
	int		i;
	int		j;

	str = c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (str == c && s[i] != c)
		{
			j++;
		}
		str = s[i];
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;
	int		j;

	word = 0;
	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (0);
	while (s[j] && s[i] && word < count_word(s, c))
	{
		i = j;
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[word++] = substr_can_free(s, i, j - i);
		if (!tab[word - 1])
			return (free_everything(tab, word));
	}
	tab[word] = NULL;
	return (tab);
}
