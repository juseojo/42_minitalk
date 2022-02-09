/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:47:18 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/10 03:24:57 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	trim(char *result, char const *s1, size_t len, size_t i)
{
	int	j;

	j = 0;
	while (i < len)
	{
		result[j] = s1[i];
		j++;
		i++;
	}
	result[j] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1) + 1;
	while (ft_strchr(set, s1[len - 1]) && len)
		len--;
	if (len == 0)
		return ("\0");
	while (ft_strchr(set, s1[i]))
		i++;
	result = (char *)malloc(len - i + 1);
	if (result == 0)
		return (0);
	trim(result, s1, len, i);
	return (result);
}
