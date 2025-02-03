/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:01:25 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 02:12:52 by nightcore        ###   ########.fr       */
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

	tmp = ACCEPTED_CHARS;
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

static void	skip_pre_map_whitespace(int fd, char *buf, int *bytes_read)
{
	read(fd, buf, 1);
	while (is_whitespace(buf[0]))
	{
		(*bytes_read)++;
		read(fd, buf, 1);
	}
}

t_map_info	get_map_infos(int fd, int *bytes_read)
{
	t_map_info	mi;
	int			i;
	char		buf[1];

	skip_pre_map_whitespace(fd, buf, bytes_read);
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
			if (read(fd, buf, 1) == 0)
				break ;
		}
		if (i == 0)
			return (print_error(MAP_NL_ERR), (t_map_info){.x = 0, .y = 0});
		mi.x++;
		if (read(fd, buf, 1) == 0)
			break ;
	}
	return (mi);
}
