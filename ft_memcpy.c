/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:39:03 by seongjch          #+#    #+#             */
/*   Updated: 2021/11/16 16:23:34 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*b_dst;
	unsigned char	*b_src;
	int				i;

	i = 0;
	b_dst = dst;
	b_src = src;
	while (i < n)
	{
		*(b_dst + i) = *(b_src + i);
		i++;
	}
	return (dst);
}
