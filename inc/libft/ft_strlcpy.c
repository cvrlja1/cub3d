/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:33 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/11 21:04:38 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = ft_strlen(src);
	if (size < 1)
		return (n);
	while (*src && i++ < size - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (n);
}

/*
int main() {
	char dst[20];
	char *src = "lorem ipsum";

	printf("%zu\n", ft_strlcpy(dst, src, 15));
	printf("%s\n", dst);
}
*/