/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <seongjch@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 06:38:18 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/09 16:24:38 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b_s1;
	unsigned char	*b_s2;
	size_t			cnt;

	if (n == 0)
		return (0);
	b_s1 = (unsigned char *)s1;
	b_s2 = (unsigned char *)s2;
	cnt = 0;
	while (cnt < n)
	{
		if (b_s1[cnt] != b_s2[cnt])
			return ((int)(b_s1[cnt] - b_s2[cnt]));
		cnt ++;
	}
	return (0);
}
