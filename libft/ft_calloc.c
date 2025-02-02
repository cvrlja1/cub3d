/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:33:44 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/10 17:21:52 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	arr = (void *)malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}

/*
int main() {
	char *str = ft_calloc(5, sizeof(char));
	free(str);
}
*/