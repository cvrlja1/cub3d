/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:36:59 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 17:14:03 by nightcore        ###   ########.fr       */
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
	printf("------------------------------\n All type identifiers found!!\n\
------------------------------\n");
	return (true);
}

char	*debug_get_id_str(t_identifier id)
{
	if (id == EA)
		return ("EA");
	if (id == WE)
		return ("WE");
	if (id == SO)
		return ("SO");
	if (id == NO)
		return ("NO");
	if (id == C)
		return ("C");
	if (id == F)
		return ("F");
	return ("NO_ID");
}

static void	debug_print_id(int fd, char *buf, int *bytes_read, t_id_info *id_info)
{
	int	read_res;

	printf("Found type identifier \'%s\':\n", debug_get_id_str(id_info->id));
	write(1, "\t", 1);
	while (*buf != '\n')
	{
		write(1, buf, 1);
		read_res = read(fd, buf, 1);
		*bytes_read += read_res;
	}
	write(1, "\n", 1);
	if (id_info->id == C || id_info->id == F)
		*(int *)id_info->ptr_ref = 0x11FF00;
}

static bool	try_read(t_textures *t, int fd, int *bytes_read)
{
	t_id_info	id_info;
	char		buf[1];

	buf[0] = ' ';
	while (!has_found_all_identifiers(t))
	{
		while (is_whitespace(buf[0]))
			*bytes_read += read(fd, buf, 1);
		id_info = find_id_info(t, buf, fd, bytes_read);
		if (!is_valid_id_info(&id_info))
			return (false);
		while (is_whitespace(*buf))
		{
			if (*buf == '\n')
				return (print_error(PARSE_NL_ERR), false);
			*bytes_read += read(fd, buf, 1);
		}
		debug_print_id(fd, buf, bytes_read, &id_info);
	}
	return (true);
}

bool	try_initialize_texture_struct(t_textures *t)
{
	t->no_path = (char *) ft_calloc(2, sizeof(char));
	t->ea_path = (char *) ft_calloc(2, sizeof(char));
	t->so_path = (char *) ft_calloc(2, sizeof(char));
	t->we_path = (char *) ft_calloc(2, sizeof(char));
	if (t->no_path == NULL || t->ea_path == NULL \
		|| t->so_path == NULL || t->we_path == NULL)
		return (print_error(MALLOC_ERR), false);
	t->ceil_clr = -1;
	t->ceil_clr = -1;
	t->flr_clr = -1;
	return (true);
}

bool	try_get_textures(t_cub_data *data, int fd, int *bytes_read)
{
	data->textures = (t_textures *) ft_calloc(1, sizeof(t_textures));
	if (data->textures == NULL)
		return (false);
	if (!try_initialize_texture_struct(data->textures))
		return (false);
	if (!try_read(data->textures, fd, bytes_read))
		return (false);
	return (true);
}
