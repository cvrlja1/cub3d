/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:16:01 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/25 16:48:13 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	if (d <= s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		s += n - 1;
		d += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

/*
int main()
{
	char dest[25];
	char src[] = "Hello,World HOW ARE YOU";

	ft_memmove(src+3, src, 15);
	printf("%s\n", src);

	return 0;
}
*/