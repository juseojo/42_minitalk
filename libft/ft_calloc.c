/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:05:47 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/05 01:41:51 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buf;
	size_t		i;

	i = 0;
	if (count * size < count)
		return (0);
	buf = malloc(count * size);
	if (buf == 0)
		return (0);
	ft_bzero(buf, count * size);
	return (buf);
}
