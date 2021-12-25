/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <seongjch@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 06:38:18 by seongjuncho       #+#    #+#             */
/*   Updated: 2021/12/26 06:01:57 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b_s1;
	unsigned char	*b_s2;
	unsigned int	cnt;

	b_s1 = s1;
	b_s2 = s2;
	cnt = 0;
	while (cnt < n)
	{
		if (*(b_s1 + cnt) < *(b_s2 + cnt))
		{
			return (1);
		}
		else if (*(b_s1 + cnt) > *(b_s2 + cnt))
		{
			return (-1);
		}
		cnt++;
	}
	return (0);
}
