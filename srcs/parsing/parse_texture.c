/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:34:58 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 19:11:34 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	try_parse_texture(t_id_info *info, int fd, char *buf, int *bytes_read)
{
	ssize_t	read_res;
	char	**ref;
	char	*tmp;

	ref = (char **) info->ptr_ref;
	while (!is_whitespace(*buf))
	{
		tmp = ft_strjoin(*ref, buf);
		if (tmp == NULL)
			return (print_error(MALLOC_ERR), false);
		free(*ref);
		*ref = tmp;
		read_res = read(fd, buf, 1);
		if (read_res == -1)
			return (print_error(READ_FD_ERR), false);
		*bytes_read += read_res;
	}
	return (true);
}
