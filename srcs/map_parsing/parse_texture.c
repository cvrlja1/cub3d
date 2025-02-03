/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:34:58 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 17:55:23 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	try_parse_texture(t_id_info *info, int fd, char *buf, int *bytes_read)
{
	char	*ref;
	char	*tmp;
	
	ref = (char *) info->ptr_ref;
	while (!is_whitespace(*buf))
	{

		ref = ft_strjoin(ref, buf);
		if (ref == NULL)
			return (print_error(MALLOC_ERR), false);
		tmp = NULL;
		(void) tmp;
		*bytes_read += read(fd, buf, 1);
	}
	return (true);
}
