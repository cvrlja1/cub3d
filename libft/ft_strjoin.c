/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:36:55 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/03 17:53:01 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count;

	if (!s1 || !s2)
		return (0);
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	count = 0;
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	while (*s2)
	{
		str[count] = *s2;
		count++;
		s2++;
	}
	str[count] = 0;
	return (str);
}

/*
int main() {
	char *s1 = "AAAAA";
	char *s2 = "BBBBB";
	char *res = ft_strjoin(s1, s2);

	printf("%s\n", res);
}
*/