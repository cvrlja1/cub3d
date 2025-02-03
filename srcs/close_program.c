/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:00:10 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 01:28:39 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_arr(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
	map = NULL;
}

static void	free_init_data(t_init_data *map)
{
	if (map == NULL)
		return ;
	if (map->map != NULL)
		free_map_arr(map->map);
	free(map);
}

void	close_cub(t_cub_data *data)
{
	if (data == NULL)
		return ;
	if (data->init != NULL)
		free_init_data(data->init);
}
