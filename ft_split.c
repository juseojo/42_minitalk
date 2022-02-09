/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:48:42 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/02/10 03:26:46 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/*									      */
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
			str_flag = 0;
		i++;
	}
	return (word);
}

int	spl_mem(char const *s, char c, char **result)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] || len != 0)
	{
		if (s[i] != c)
			len++;
		if ((s[i - 1] != c && s[i] == c) || (!s[i] && len != 0))
		{
			result[j] = (char *)malloc(len + 1);
			if (result[j] == 0)
				return (0);
			if (s[i] == 0)
				break ;
			len = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void	spl(char const *s, char c, char **result)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
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
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
	{
		result = malloc(0);
		return (result);
	}
	result = (char **)malloc(sizeof(char *) * word_count(s, c));
	if (result == 0)
		return (0);
	while (s[i] == c)
		i++;
	if (!(spl_mem(s + i, c, result)))
		return (0);
	spl(s, c, result);
	return (result);
}
