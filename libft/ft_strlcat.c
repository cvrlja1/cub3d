/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:32 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/25 16:32:06 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		total;
	size_t		len_dst;

	if ((!dst || !src) && !size)
		return (0);
	total = 0;
	len_dst = 0;
	while (*(dst + len_dst) && len_dst < size)
		len_dst++;
	if (len_dst < size)
		total = len_dst + ft_strlen(src);
	else
		return (size + ft_strlen(src));
	while (len_dst < size - 1 && *src)
	{
		*(dst + len_dst++) = *src++;
	}
	*(dst + len_dst) = '\0';
	return (total);
}

/*
int main() {
	char d[20] = "pqrstuvwxyz";
	char *s = "abcdffgdfggfsg";

	printf("%zu\n", ft_strlcat(d, s, 20));
	printf("%s\n", d);
}
*/