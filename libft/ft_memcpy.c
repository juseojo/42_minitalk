/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:39:03 by seongjch          #+#    #+#             */
/*   Updated: 2022/02/03 19:28:20 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char	*b_dst;
	unsigned char	*b_src;
	size_t		i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	b_dst = (unsigned char *)dst;
	b_src = (unsigned char *)src;
	while (i < n)
	{
		*(b_dst + i) = *(b_src + i);
		i++;
	}
	return (dst);
}
