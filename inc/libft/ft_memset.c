/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:16:21 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/25 16:48:23 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}

/*
int	main(void)
{
	int t[7] = {1, 2, 3, 4, 5, 6, 7};
	int p = sizeof(t) / sizeof(t[0]);
	int i;
	memset(t, 1, 12);
	i = 0;
	while (i < p)
	{
		printf("%d\n", t[i]);
		i++;
	}
}
*/
