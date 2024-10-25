/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:29:17 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/24 06:16:21 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_digit(int num)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		len = 1;
		return (len);
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	itouille(int n, int ne, int i, char *output)
{
	if (n < 0)
	{
		ne = 1;
		output[0] = '-';
		n = -n;
	}
	while (i >= ne)
	{
		output[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		ne;
	int		len;
	char	*output;

	ne = 0;
	len = count_digit(n);
	if (n < 0)
		len++;
	i = len - 1;
	if (n < -2147483647)
		return (ft_strdup("-2147483648"));
	output = (char *)malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	if (n == 0)
	{
		output[0] = '0';
		return (output);
	}
	itouille(n, ne, i, output);
	return (output);
}
