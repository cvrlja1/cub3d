/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:28:55 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/17 17:10:20 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;

	j = 0;
	if (!*little || !little[j])
		return ((char *)big);
	if (!len)
		return (NULL);
	i = 0;
	while (big[i])
	{
		j = 0;
		if (big[i + j] == little[j])
		{
			while (big[i + j] == little[j] && (j + i) < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}

/*
int main() {
	const char *str1 = "bbbbaaaaabb";
	const char *str2 = "aaaaa";
	size_t max = 6;
	char *res = ft_strnstr(str1, str2, max);
	printf("%s\n", res);
}
*/