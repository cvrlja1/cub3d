/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:53:41 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 03:41:16 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	place_char_on_map(char *map_pos, char c)
{
	static char	last_char = '\0';

	if (c == '\n')
	{
		last_char = '0';
	}
	if (is_whitespace(c))
	{
		if (last_char == '1' || last_char == '\0')
		{
			c = '\0';
		}
		else
			c = '0';
	}
	*map_pos = c;
	last_char = c;
}

/*
 * SET PLAYER STARTING POSITION AND ROTATION HERE
 */
static void	handle_special_map_char(t_cub_data *data, char *c)
{
	if (*c == 'N' || *c == 'E' || *c == 'S' || *c == 'W')
	{
		(void) data;
		*c = '0';
	}
}

bool	try_fill_map_arr(t_cub_data *data, char **map, int fd)
{
	ssize_t	bytes_read;
	char	buf[1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (1)
	{
		bytes_read = read(fd, buf, 1);
		if (bytes_read == 0)
			return (true);
		if (bytes_read == -1)
			return (print_error(READ_FD_ERR), false);
		if (buf[0] == '\n')
		{
			j = 0;
			i++;
			continue ;
		}
		handle_special_map_char(data, &buf[0]);
		place_char_on_map(&map[i][j++], buf[0]);
		//map[i][j++] = buf[0];
	}
	return (true);
}
