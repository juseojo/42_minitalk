/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:41:16 by seongjch          #+#    #+#             */
/*   Updated: 2022/02/09 17:27:25 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\v'\
			|| ch == '\r' || ch == '\f')
	{
		return (1);
	}
	return (0);
}

int	cut(char	*str, int *i, int *j)
{
	int	minus;
	int	plus;

	*i = 0;
	*j = 0;
	minus = 0;
	plus = 0;
	while (str[*i] && !('0' <= str[*i] && str[*i] <= '9'))
	{
		if (str[*i] == '-')
			minus++;
		if (str[*i] == '+')
			plus++;
		if (str[*i] != '-' && str[*i] != '+' && !is_space(str[*i]))
			return (-1);
		if (minus > 1)
			return (-1);
		if ((minus > 0 || plus > 0) && is_space(str[*i]))
			return (-1);
		*i = *i + 1;
	}
	if (minus)
		return (1);
	return (0);
}

long	cul_result(char *str, int sign, int *i, int *j)
{
	long	result;
	long	dig;
	long	count;

	dig = 1;
	result = 0;
	count = 0;
	while (*j > 0)
	{
		result += (str[*i + *j - 1] - '0') * dig;
		if (result < (str[*i + *j - 1] - '0') * dig)
		{
			if (sign)
				return (0);
			else
				return (-1);
		}
		dig *= 10;
		*j = *j - 1;
	}
	return (result);
}

int	ft_atoi(char	*str)
{
	int		i;
	int		j;
	int		sign_minus;
	long	result;

	sign_minus = cut(str, &i, &j);
	while (str[i + j] && '0' <= str[i + j] && str[i + j] <= '9')
		j = j + 1;
	result = cul_result(str, sign_minus, &i, &j);
	if (sign_minus == -1)
		return (0);
	if (sign_minus)
	{
		result = -result;
	}
	return (result);
}
