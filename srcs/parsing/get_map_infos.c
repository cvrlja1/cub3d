/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:01:25 by nightcore         #+#    #+#             */
/*   Updated: 2025/07/01 14:31:11 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_player_spawn(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

static bool	is_accepted_char(char c, t_map_info *mi)
{
	char	*tmp;

	tmp = ACCEPTED_MAP_CHARS;
	while (*tmp != '\0')
	{
		if (c == *tmp)
		{
			if (!is_player_spawn(c))
				return (true);
			if (mi->spawn_count != 0)
				return (print_error(UPPER_SPWN_ERR), false);
			mi->spawn_count++;
			return (true);
		}
		tmp++;
	}
	return (print_error(MAP_CHAR_ERR), false);
}

static bool	skip_pre_map_whitespace(int fd, char *buf, int *bytes_read)
{
	int		nl_offset;
	ssize_t	bytes;

	nl_offset = 0;
	bytes = read(fd, buf, 1);
	if (bytes == -1)
		return (false);
	while (is_whitespace(buf[0]))
	{
		nl_offset++;
		if (buf[0] == '\n')
		{
			(*bytes_read) += nl_offset;
			nl_offset = 0;
		}
		bytes = read(fd, buf, 1);
		if (bytes == -1)
			return (false);
	}
	return (true);
}

static bool	try_read_map_line(int fd, char *buf, t_map_info *mi)
{
	ssize_t	bytes_read;
	int		i;

	i = 0;
	while (buf[0] != '\n')
	{
		if (!is_accepted_char(buf[0], mi))
			return (false);
		if (++i > mi->y)
			mi->y = i;
		bytes_read = read(fd, buf, 1);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
			return (print_error(READ_FD_ERR), false);
	}
	if (i == 0)
		return (print_error(MAP_NL_ERR), false);
	return (true);
}

t_map_info	get_map_infos(int fd, int *bytes_read)
{
	t_map_info	mi;
	char		buf[1];

	if (!skip_pre_map_whitespace(fd, buf, bytes_read))
		return ((t_map_info){-1, -1, NULL, -1});
	mi = (t_map_info){.x = 0, .y = 0, .spawn_count = 0};
	while (1)
	{
		if (!try_read_map_line(fd, buf, &mi))
			return ((t_map_info){.x = 0, .y = 0});
		mi.x++;
		if (read(fd, buf, 1) == 0)
			break ;
	}
	return (mi);
}
