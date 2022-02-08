/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:48:42 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/08 20:24:22 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	str_flag;
	int	word;

	i = 0;
	word = 0;
	str_flag = 0;
	while (s[i] != 0)
	{
		if (str_flag == 0 && s[i] != c)
		{
			word++;
			str_flag = 1;
		}
		if (s[i] == c)
		{
			str_flag = 0;
		}
		i++;
	}
	return (word);
}

int	spl_mem(char const *s, char c, char **result)
{
	int	i;
	int	len;
	int	j;
	int	str_flag;

	i = 0;
	j = 0;
	str_flag = 0;
	len = 0;
	while (s[i] != 0)
	{
 		if (s[i] != c)
		{
			len++;
			str_flag = 1;
		}
		if (str_flag == 1 && s[i] == c)
		{
			if (!(result[j] = (char *)malloc(len + 1)))
				return (0);
			len = 0;
			j++;
			str_flag = 0;
		}
		i++;
	}
	if (len != 0 && !(result[j] = (char *)malloc(len + 1)))
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (c == '\0')
	{
		result = malloc(0);
		return (result);
	}
	if (!(result = (char **)malloc(sizeof(char *) * word_count(s, c))))
			return (0);
	if (!(spl_mem(s, c, result)))
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			result[j][k] = s[i];
			k++;
		}
		if (s[i] == c && k)
		{
			result[j][k] = 0;
			k = 0;
			j++;
		}
		i++;
	}
	return (result);
}
