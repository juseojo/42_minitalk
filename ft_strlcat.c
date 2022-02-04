/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:16:52 by seongjch          #+#    #+#             */
/*   Updated: 2022/01/21 05:41:25 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int	size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dst_len;

	dst_len = str_len(dest);
	src_len = str_len(src);
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (src_len + dst_len);
}
