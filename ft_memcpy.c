/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:39:03 by seongjch          #+#    #+#             */
/*   Updated: 2021/12/26 06:01:17 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char	*b_dst;
	unsigned char	*b_src;
	unsigned int	i;

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
