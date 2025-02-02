/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:37:48 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/17 17:39:44 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	c;

	c = 0;
	if (n < 1)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static char	*check_special_cases(char *s, int *i)
{
	if (*i == 0)
	{
		*s = *i + '0';
		return (s);
	}
	else if (*i == -2147483648)
	{
		*s = '-';
		s++;
		*s = 2 + '0';
		s--;
		*i = 147483648;
		return (s);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	char	*buff;

	size = get_size(n);
	res = (char *)malloc(size * sizeof(char) + 1);
	if (!res)
		return (NULL);
	buff = res;
	check_special_cases(res, &n);
	if (n < 0)
	{
		*res = '-';
		n *= -1;
	}
	res += size;
	*res-- = '\0';
	while (n)
	{
		*res = n % 10 + '0';
		n /= 10;
		if (n)
			res--;
	}
	return (buff);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(-200));
}
*/
