/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:03:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/03 01:58:07 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_print_map(char **map)
{
	int	i;

	i = 0;
	printf("Showing map:\n\n");
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_cub_data	data;

	if (!try_parse_map(argc, argv, &data))
		return (1);
	debug_print_map(data.init->map);
	close_cub(&data);
	return (0);
}
