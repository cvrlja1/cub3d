/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:59:03 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/22 16:47:06 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			if (*(s + 1) == c || *(s + 1) == '\0')
				i++;
			s++;
		}
	}
	return (i);
}

static void	mem_free(char **s, int p)
{
	int	i;

	i = 0;
	while (i < p)
		free(s[i++]);
	free(s);
}

static char	*memory_all(int size)
{
	char	*res;

	res = (char *)malloc(size * sizeof(char) + 1);
	if (!res)
	{
		return (NULL);
	}
	return (res);
}

static char	*split(char **s, char c)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	while (**s == c)
		(*s)++;
	while (**s != c && **s != '\0')
	{
		(*s)++;
		len++;
	}
	(*s) -= len;
	str = memory_all(len);
	if (!str)
		return (NULL);
	while (**s != c && **s != '\0')
	{
		str[i++] = **s;
		(*s)++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_c;
	int		t;

	if (!s)
		return (NULL);
	t = 0;
	word_c = count_words(s, c);
	res = (char **)malloc(word_c * sizeof(char *) + 8);
	if (!res)
		return (NULL);
	while (t < word_c)
	{
		res[t] = split((char **)&s, c);
		if (!res[t])
		{
			mem_free(res, t);
			return (NULL);
		}
		t++;
	}
	res[t] = NULL;
	return (res);
}
