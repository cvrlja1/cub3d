/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:26:30 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/02 21:45:52 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	try_get_map_file_fd(char *file)
{
	(void) file;
	return (0);
}

bool	try_parse_args(int argc, char **argv)
{
	int	fd;

	if (argc > 2)
		return (print_error(LESSER_ARG_ERR), false);
	else if (argc < 2)
		return (print_error(UPPER_ARG_ERR), false);
	fd = try_get_map_file_fd(argv[1]);
	if (fd < 0)
		return (false);
	return (true);
}
