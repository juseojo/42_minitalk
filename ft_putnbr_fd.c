/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:31:49 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/03/30 16:33:22 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long long n, int fd)
{
	long long	ln;	
	int	cnt;

	cnt = 0;
	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
		cnt++;
	}
	if (ln > 9)
	{
		cnt += ft_putnbr_fd(ln / 10, fd);
	}
	ft_putchar_fd(ln % 10 + '0', fd);
	cnt++;
	return (cnt);
}
