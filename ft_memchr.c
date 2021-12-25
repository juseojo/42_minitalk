/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <seongjch@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 00:59:51 by seongjuncho       #+#    #+#             */
/*   Updated: 2021/12/26 05:36:02 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b_s;
	unsigned int	cnt;

	cnt = 0;
	b_s = s;
	while (cnt < n)
	{
		if (*(b_s + cnt) == c)
		{
			return (b_s + cnt);
		}
		cnt++;
	}
	return (0);
}
