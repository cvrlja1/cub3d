/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:44:01 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/25 15:09:48 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0 || (!s1[i] && !s2[i]))
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int	main() {
	printf("%d\n", ft_strncmp("atpdk", "atpdk", 10));
	printf("%d\n", strncmp("atpdk", "atpdk", 10));
}
*/
