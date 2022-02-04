/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:30:12 by seongjch          #+#    #+#             */
/*   Updated: 2022/02/02 04:12:51 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*bt;
	int				i;

	bt = (unsigned char *)s;
	i = 0;
	while (i < (int)n)
	{
		*(bt + i) = 0;
		i++;
	}
}
