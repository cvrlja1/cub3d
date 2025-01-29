/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:41:47 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/25 16:46:31 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*srcs;
	unsigned char	*dests;
	size_t			i;

	srcs = (unsigned char *) src;
	dests = (unsigned char *)dest;
	i = 0;
	if (!srcs && !dests)
		return (NULL);
	while (i < n)
	{
		dests[i] = srcs[i];
		i++;
	}
	return (dest);
}

/*
int main() {
	char dst[20];
	char src[] = "Copy this to dst!";

	ft_memcpy(src+3, src, 10);
	printf("%s", src);
}
*/