/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:54:54 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/12 18:00:02 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	while (*s != (char)c && i != 0)
	{
		i--;
		s--;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
