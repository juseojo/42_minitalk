/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <seongjch@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 06:55:38 by seongjuncho       #+#    #+#             */
/*   Updated: 2021/12/25 00:29:55 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	cnt;

	cnt = 0;
	while (cnt < len)
	{
		if (dst[cnt] == src[cnt])
		{
			cnt++;
			continue ;
		}
		dst[cnt] = src[cnt];
		cnt++;
	}
	return (dst);
}
