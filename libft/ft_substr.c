/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:44:33 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/06 22:44:59 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!(result = malloc(sizeof(char) * (len + 1))))
			return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	ft_strlcpy(result, s + start, len + 1);
	return(result);
}
