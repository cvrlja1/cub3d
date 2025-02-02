/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:04:16 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/22 14:41:54 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*res;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	res = (char *)malloc(size * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (*s)
	{
		*res++ = (*f)(i++, *s++);
	}
	*res = '\0';
	return (res - size);
}
