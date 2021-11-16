/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:01:05 by seongjch          #+#    #+#             */
/*   Updated: 2021/11/16 15:04:38 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*str;
	int				i;

	str = ptr;
	i = 0;
	while (i < num)
	{
		*(str + i) = value;
		i++;
	}
	return (ptr);
}
