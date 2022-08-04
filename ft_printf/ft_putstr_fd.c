/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:09:50 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/04/09 18:17:00 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		if (write(fd, s, ft_strlen(s)) == -1)
			return (-1);
		return (ft_strlen(s));
	}
	if (write(fd, "(null)", 6) == -1)
		return (-1);
	return (6);
}
