/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:36:59 by nightcore         #+#    #+#             */
/*   Updated: 2025/03/26 22:58:29 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	has_found_all_identifiers(t_textures *t)
{
	if (t->ceil_clr == -1 || t->flr_clr == -1)
		return (false);
	if (t->no_path == NULL)
		return (false);
	if (t->ea_path == NULL)
		return (false);
	if (t->so_path == NULL)
		return (false);
	if (t->we_path == NULL)
		return (false);
	return (true);
}

static bool	try_parse_info(t_id_info *inf, int fd, char *buf, int *bytes_read)
{
	ssize_t	read_res;

	while (is_whitespace(*buf))
	{
		if (*buf == '\n')
			return (print_error(PARSE_NL_ERR), false);
		read_res = read(fd, buf, 1);
		if (read_res == -1)
			return (print_error(READ_FD_ERR), false);
		*bytes_read += read_res;
	}
	if (inf->id == C || inf->id == F)
	{
		if (!try_parse_color(inf, fd, buf, bytes_read))
			return (false);
	}
	else
	{
		if (!try_load_wall_texture(inf, data, \
				get_wall_texture_path(inf, fd, buf, bytes_read)))
		{
			return (false);
		}
		//if (!try_parse_texture(inf, fd, buf, bytes_read))
			//return (false);
	}
	return (true);
}

static bool	try_read(t_cub_data *data, int fd, int *bytes_read)
{
	t_id_info	id_info;
	ssize_t		read_res;
	char		buf[1];

	buf[0] = ' ';
	while (!has_found_all_identifiers(data->textures))
	{
		while (is_whitespace(buf[0]))
		{
			read_res = read(fd, buf, 1);
			if (read_res == -1)
				return (print_error(READ_FD_ERR), false);
			*bytes_read += read_res;
		}
		id_info = find_id_info(data->textures, buf, fd, bytes_read);
		if (!is_valid_id_info(&id_info))
			return (false);
		if (!try_parse_info(&id_info, fd, buf, bytes_read))
			return (false);
	}
	return (true);
}

bool	try_get_textures(t_cub_data *data, int fd, int *bytes_read)
{
	data->textures = (t_textures *) ft_calloc(1, sizeof(t_textures));
	if (data->textures == NULL)
		return (false);
	data->textures->ceil_clr = -1;
	data->textures->flr_clr = -1;
	if (!try_read(data, fd, bytes_read))
		return (false);
	return (true);
}
