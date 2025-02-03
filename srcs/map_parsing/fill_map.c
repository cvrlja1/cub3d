/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:53:41 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 02:32:30 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
 * SET PLAYER STARTING POSITION AND ROTATION HERE
 */
static void	handle_special_map_char(t_cub_data *data, char *c)
{
	if (*c == 'N' || *c == 'E' || *c == 'S' || *c == 'W')
	{
		(void) data;
	}
	*c = '0';
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
		if (buf[0] != '0' && buf[0] != '1')
			handle_special_map_char(data, &buf[0]);
		map[i][j++] = buf[0];
	}
	return (true);
}
