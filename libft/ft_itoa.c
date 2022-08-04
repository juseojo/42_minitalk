/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:31:49 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/12 17:39:07 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*except(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}

static char	*insert(int i, long dig, int n, int len)
{
	char	*result;

	dig /= 10;
	if (n < 0)
	{
		len++;
		result = (char *)malloc(len + 1);
		if (result == 0)
			return (0);
		result[0] = '-';
		i++;
		n = -n;
	}
	else
		result = (char *)malloc(len + 1);
	if (result == 0)
		return (0);
	while (i < len)
	{
		result[i] = (n / dig) % 10 + 48;
		i++;
		dig /= 10;
	}
	result[len] = 0;
	return (result);
}

char	*ft_itoa(int n)
{
	long	dig;
	int		len;
	int		i;

	i = 0;
	len = 0;
	dig = 1;
	while (n / dig)
	{
		dig *= 10;
		len++;
	}
	if (n == 0 || n == -2147483648)
		return (except(n));
	return (insert(i, dig, n, len));
}
