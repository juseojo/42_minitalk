/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:31:49 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/09 01:58:03 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	long	dig;
	int	len;
	int	i;

	i = 0;
	len = 0;
	dig = 1;
	if (n == 0)
		return (ft_strdup("0"));
	while (n / dig)
	{
		dig *= 10;
		len++;
	}
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		len++;
	}
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	dig /= 10;
	if (n < 0)
	{
		result[0] = '-';
		i++;
		n = -n;
	}
	while (i < len)
	{
		result[i] = (n / dig) % 10 + 48;
		i++;
		dig /= 10;
	}
	result[len] = 0;
	return (result);
}
