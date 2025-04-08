/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:34:58 by nightcore         #+#    #+#             */
/*   Updated: 2025/04/08 12:52:03 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	try_increase_buffer(char **path, int i, int *buffer_size)
{
	char	*tmp;
	int		j;

	(*buffer_size) += 10;
	tmp = (char *) ft_calloc(*buffer_size + 1, sizeof(char));
	if (tmp == NULL)
		return (print_error(MALLOC_ERR), false);
	j = 0;
	while (j < i)
	{
		tmp[j] = (*path)[j];
		j++;
	}
	if (*path != NULL)
		free(*path);
	*path = tmp;
	return (true);
}

bool	try_parse_texture(t_id_info *info, int fd, char *buf, int *bytes_read)
{
	ssize_t	read_res;
	char	**path;
	int		i;
	int		buffer_size;

	path = (char **) info->ptr_ref;
	i = 0;
	buffer_size = 0;
	while (!is_whitespace(*buf))
	{
		if (i >= buffer_size)
			if (!try_increase_buffer(path, i, &buffer_size))
				return (false);
		(*path)[i] = buf[0];
		read_res = read(fd, buf, 1);
		if (read_res == -1)
			return (print_error(READ_FD_ERR), false);
		*bytes_read += read_res;
		i++;
	}
	return (true);
}
