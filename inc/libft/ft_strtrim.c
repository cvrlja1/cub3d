/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:41:30 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/17 17:43:33 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iscont(char const *setc, char c)
{
	while (*setc)
	{
		if (*setc == c)
			return (1);
		setc++;
	}
	return (0);
}

static char	*getstart(char const *s1, char const *set)
{
	while (*s1 && iscont(set, *s1) == 1)
	{
		s1++;
	}
	return ((char *)s1);
}

static char	*getend(char const *s1, char const *set)
{
	while (*s1)
		s1++;
	s1--;
	while (iscont(set, *s1) == 1)
		s1--;
	return ((char *)s1);
}

static char	*empty(char const *s1)
{
	char	*str;

	str = (char *)s1;
	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*temp;
	char	*end;
	int		len;

	res = NULL;
	if (!s1 || !set)
		return (empty(res));
	s1 = getstart(s1, set);
	if (*s1 == '\0')
		return (empty(res));
	end = getend(s1, set);
	len = (end - s1) + 1;
	res = (char *)malloc(len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	temp = res;
	while (s1 != end + 1)
		*temp++ = *s1++;
	*temp = '\0';
	return (res);
}

/*
int main() {
	char *str = "";
	char *set = "";
	char *res = ft_strtrim(str, set);
	printf("%s\n", res);
}
*/