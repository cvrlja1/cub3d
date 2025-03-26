/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:34:58 by nightcore         #+#    #+#             */
/*   Updated: 2025/03/26 22:56:04 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	try_increase_buffer(char **path, int i, int *buffer_size)
{
	char	*tmp;
	int		j;

	(*buffer_size) += 10;
	tmp = (char *) ft_calloc(buffer_size + 1, sizeof(char));
	if (tmp == NULL)
		return (printf_error(MALLOC_ERR), false);
	j = 0;
	while (j < i)
	{
		tmp[j] = (*path)[j];
	}
	if (*path != NULL)
		free(*path);
	*path = tmp;
	return (true);
}

char	*get_wall_texture_path(int fd, char *buf, int *bytes_read)
{
	ssize_t	read_res;
	char	*path;
	int		i;
	int		buffer_size;

	path = NULL;
	i = 0;
	buffer_size = 0;
	while (!is_whitespace(*buf))
	{
		if (i >= buffer_size)
			if (!try_increase_buffer(&path, i, &buffer_size))
				return (false);
		path[i] = buf[0];
		read_res = read(fd, buf, 1);
		if (read_res == -1)
			return (print_error(READ_FD_ERR), false);
		*bytes_read += read_res;
	}
	if (path != NULL)
		free(path);
	return (path);
}

bool	try_load_wall_texture(t_id_info *info, t_cub_data *data, char *path)
{
	t_image	**ref;

	if (path == NULL)
		return (false);
	ref = (t_image **) info->ptr_ref;
	*ref = load_texture(path, data);
	free(path);
	return (*ref == NULL);
}
