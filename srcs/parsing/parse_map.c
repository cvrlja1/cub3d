/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:15:15 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 18:31:34 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	**create_map_arr(t_map_info mi)
{
	char	**map;
	int		i;

	map = (char **) ft_calloc(mi.x + 1, sizeof(char *));
	if (map == NULL)
		return (map);
	i = 0;
	while (i < mi.x)
	{
		map[i] = (char *) ft_calloc(mi.y + 1, sizeof(char));
		if (map[i] == NULL)
			return (print_error(MALLOC_ERR), free_map_arr(map), NULL);
		i++;
	}
	return (map);
}

static bool	has_valid_map_info(t_map_info mi)
{
	if (mi.x < 1 || mi.y < 1)
		return (false);
	if (mi.spawn_count == 0)
		return (print_error(LESSER_SPWN_ERR), false);
	return (true);
}

static bool	try_reopen_fd(char *path, int *fd, int bytes_read)
{
	char	tmp[1];
	int		i;

	*fd = open(path, O_RDONLY);
	if (*fd < 0)
		return (print_error(OPEN_FD_ERR), false);
	i = 0;
	while (i < bytes_read)
	{
		if (read(*fd, tmp, 1) < 0)
			return (print_error(READ_FD_ERR), close(*fd), false);
		i++;
	}
	return (true);
}

char	**get_map_arr(t_cub_data *data, char *file_path, int fd, int bytes_read)
{
	t_map_info	mi;

	mi = get_map_infos(fd, &bytes_read);
	close(fd);
	if (!has_valid_map_info(mi))
		return (NULL);
	mi.map = create_map_arr(mi);
	if (mi.map == NULL)
		return (mi.map);
	if (!try_reopen_fd(file_path, &fd, bytes_read))
		return (free_map_arr(mi.map), NULL);
	if (!try_fill_map_arr(data, mi.map, fd))
		return (free_map_arr(mi.map), close(fd), NULL);
	close(fd);
	data->map->x_len = mi.x;
	data->map->y_len = mi.y;
	if (!check_map(mi.map, mi.y, mi.x))
		return (free_map_arr(mi.map), print_error(FLOOD_FAIL), NULL);
	return (mi.map);
}
