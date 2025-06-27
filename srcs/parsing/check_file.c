/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:26:30 by nightcore         #+#    #+#             */
/*   Updated: 2025/06/27 16:39:29 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	try_allocate_memory(t_cub_data *data)
{
	data->map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (data->map == NULL)
		return (false);
	data->player = (t_player *) ft_calloc(1, sizeof(t_player));
	if (data->player == NULL)
		return (free(data->map), false);
	data->player->mov = (t_mov_vars *) ft_calloc(1, sizeof(t_mov_vars));
	if (data->player->mov == NULL)
		return (free(data->map), free(data->player), false);
	return (true);
}

static void	initialize_data(t_cub_data *data)
{
	data->player->fov_mult = 1;
}

static bool	try_setup_data(t_cub_data *data, char *file_path, int fd)
{
	int	bytes_read;

	if (!try_allocate_memory(data))
		return (print_error(MALLOC_ERR), close(fd), false);
	bytes_read = 0;
	if (!try_get_textures(data, fd, &bytes_read))
		return (free_cub(data), close(fd), false);
	data->map->arr = get_map_arr(data, file_path, fd, bytes_read);
	if (data->map->arr == NULL)
		return (free_cub(data), false);
	initialize_data(data);
	return (true);
}

static bool	is_valid_input(int argc, char **argv)
{
	size_t	len;

	if (argc > 2)
		return (print_error(LESSER_ARG_ERR), false);
	else if (argc < 2)
		return (print_error(UPPER_ARG_ERR), false);
	len = ft_strlen(argv[1]);
	if (len < 4)
		return (print_error(MAP_EXT_ERR), false);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
		return (print_error(MAP_EXT_ERR), false);
	return (true);
}

bool	try_initialization(int argc, char **argv, t_cub_data *data)
{
	int	fd;

	if (!is_valid_input(argc, argv))
		return (false);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error(MAP_PATH_ERR), false);
	if (!try_setup_data(data, argv[1], fd))
		return (false);
	return (true);
}
