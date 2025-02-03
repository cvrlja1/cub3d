/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:26:30 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 02:14:43 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_valid_input(int argc, char **argv)
{
	size_t	len;

	if (argc > 2)
		return (print_error(LESSER_ARG_ERR), false);
	else if (argc < 2)
		return (print_error(UPPER_ARG_ERR), false);
	len = ft_strlen(argv[1]);
	if (len < 4)
		return (print_error(MAP_EXT_ERR), false);
	if (strncmp(&argv[1][len - 4], ".cub", 4) != 0)
		return (print_error(MAP_EXT_ERR), false);
	return (true);
}

static bool	try_setup_init_data(t_cub_data *data, char *file_path, int fd)
{
	int	bytes_read;

	data->init = (t_init_data *) ft_calloc(1, sizeof(t_init_data));
	if (data->init == NULL)
		return (print_error(MALLOC_ERR), close(fd), false);
	bytes_read = 0;
	/*
	 * pass this into all the functions first reading from the file descriptor 
	 * to count where the parsing for the map array starts. 
	 *
	 * Parse other arguments (COLOR, TEXTURES) before array
	 */
	data->init->map = get_map_arr(data, file_path, fd, bytes_read);
	if (data->init->map == NULL)
		return (free(data->init), false); // free things from before if it fails
	return (true);
}

bool	try_parse_map(int argc, char **argv, t_cub_data *data)
{
	int	fd;

	if (!is_valid_input(argc, argv))
		return (false);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error(MAP_PATH_ERR), false);
	if (!try_setup_init_data(data, argv[1], fd))
		return (false);
	return (true);
}
