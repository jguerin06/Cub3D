/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:59:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/23 10:30:11 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_sstrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(src) + 1;
	dest = malloc(size * sizeof(char));
	size = 0;
	if (dest == NULL)
		return (NULL);
	while (src[size])
	{
		dest[size] = src[size];
		size++;
	}
	dest[size] = '\0';
	return (dest);
}

char	**ft_sstrdup(char **s1)
{
	int		i;
	int		len;
	char	**dest;

	len = ft_sstrlen(s1);
	i = 0;
	dest = malloc(sizeof(char *) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = ft_strdup(s1[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
