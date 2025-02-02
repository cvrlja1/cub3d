/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:26:30 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/02 22:11:46 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	try_parse_map(int argc, char **argv, t_cub_data *data)
{
	int	fd;

	(void) data;
	if (!is_valid_input(argc, argv))
		return (false);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error(MAP_PATH_ERR), false);
	close(fd);
	return (true);
}
