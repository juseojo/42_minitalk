/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <seongjch@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 00:59:51 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/11 18:45:59 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b_s;
	size_t			cnt;

	cnt = 0;
	b_s = (unsigned char *)s;
	while (cnt < n)
	{
		if (*(b_s + cnt) == (unsigned char)c)
		{
			return (b_s + cnt);
		}
		cnt++;
	}
	return (0);
}
