/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:19:01 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/09 16:23:22 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (*(needle + j) && i + j < len)
		{
			if (*(haystack + i + j) != *(needle + j))
				break ;
			j++;
		}
		if (*(needle + j) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
