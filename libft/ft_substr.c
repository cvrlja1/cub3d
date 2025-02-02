/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:18:27 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/23 15:29:38 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp;

	if (!s)
		return (NULL);
	if (!*s || start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	temp = substr;
	if (start < ft_strlen(s))
		s += start;
	while (*s && len--)
		*substr++ = *s++;
	*substr = '\0';
	return (temp);
}

/*
int main() {
	char *s1 = "0123456789";
	char *s2 = ft_substr(s1, 7, 10);
	printf("%s\n", s2);
	free(s2);
}
*/