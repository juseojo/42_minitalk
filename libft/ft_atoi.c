/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:41:16 by seongjch          #+#    #+#             */
/*   Updated: 2022/02/05 02:56:45 by seongjuncho      ###   ########.fr       */
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
	long	count;
	long	drop;

	drop = 0;
	*i = 0;
	*j = 0;
	count = 2;
	while (str[*i] && !('0' <= str[*i] && str[*i] <= '9'))
	{
		if (str[*i] == '-')
			count++;
		if (str[*i] != '-' && str[*i] != '+' && !is_space(str[*i]))
			return (-1);
		if (drop && (str[*i] == '-' || str[*i] == '+'))
			return (-1);
		if (str[*i] == '-' || str[*i] == '+')
			drop = 1;
		if (drop && is_space(str[*i]))
			return (-1);
		*i = *i + 1;
	}
	while (str[*i + *j] && '0' <= str[*i + *j] && str[*i + *j] <= '9')
		*j = *j + 1;
	if (count % 2 == 0)
		return (0);
	return (1);
}

long	cul_result(char *str,int sign, int *i, int *j)
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
				return(-1);
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
	long		result;

	sign_minus = cut(str, &i, &j);
	result = cul_result(str, sign_minus, &i, &j);
	if (sign_minus == -1)
		return (0);
	if (sign_minus)
	{
		result = -result;
	}
	return (result);
}
