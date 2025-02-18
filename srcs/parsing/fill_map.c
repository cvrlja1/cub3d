/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:53:41 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 16:27:09 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	handle_special_map_char(t_cub_data *data, char *c, int x, int y)
{
	if (*c == 'N' || *c == 'E' || *c == 'S' || *c == 'W')
	{
		*data->player = (t_player){.x = x + 0.5, .y = y + 0.5, .rot = 0};
		if (*c == 'N')
			data->player->rot = 180 * M_PI / 180;
		else if (*c == 'E')
			data->player->rot = 270 * M_PI / 180;
		else if (*c == 'S')
			data->player->rot = 0 * M_PI / 180;
		else if (*c == 'W')
			data->player->rot = 90 * M_PI / 180;
		*c = WALK_CHAR;
	}
}

static void	place_char_on_map(char **map, int x, int y, char c)
{
	static char	last_char = '\0';

	if (c == '0')
		c = WALK_CHAR;
	else if (is_whitespace(c))
	{
		if (last_char == '1' || last_char == '\0')
			c = '\0';
		else
			c = WALK_CHAR;
	}
	map[x][y] = c;
	last_char = c;
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
		handle_special_map_char(data, &buf[0], i, j);
		place_char_on_map(map, i, j++, buf[0]);
	}
	return (true);
}
