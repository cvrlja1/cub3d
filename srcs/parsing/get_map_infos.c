/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:01:25 by nightcore         #+#    #+#             */
/*   Updated: 2025/07/01 12:41:47 by nicvrlja         ###   ########.fr       */
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
	read(fd, buf, 1);
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

t_map_info	get_map_infos(int fd, int *bytes_read)
{
	t_map_info	mi;
	int			i;
	char		buf[1];
	ssize_t		bytes;

	if (!skip_pre_map_whitespace(fd, buf, bytes_read))
		return ((t_map_info){-1, -1, NULL, -1});
	mi = (t_map_info){.x = 0, .y = 0, .spawn_count = 0};
	while (1)
	{
		i = 0;
		while (buf[0] != '\n')
		{
			if (!is_accepted_char(buf[0], &mi))
				return ((t_map_info){.x = 0, .y = 0});
			if (++i > mi.y)
				mi.y = i;
			bytes = read(fd, buf, 1);
			if (bytes == 0)
				break ;
			if (bytes == -1)
				return ((t_map_info){-1, -1, NULL, -1});
		}
		if (i == 0)
			return (print_error(MAP_NL_ERR), (t_map_info){.x = 0, .y = 0});
		mi.x++;
		if (read(fd, buf, 1) == 0)
			break ;
	}
	return (mi);
}
