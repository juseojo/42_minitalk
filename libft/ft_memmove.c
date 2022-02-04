/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <seongjch@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 06:55:38 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/04 17:35:16 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*b_dst;
	unsigned char	*b_src;

	if (dst == 0 && src == 0)
		return (0);
	b_src = (unsigned char *)src;
	b_dst = (unsigned char *)dst;
	if (dst < src)
	{
		while (len--)
		{
			*b_dst++ = *b_src++;
		}
	}
	else
	{
		while (len--)
		{
			*(b_dst + len) = *(b_src + len);
		}
	}
	return (dst);
}
