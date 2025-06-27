/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:48:37 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/06/27 18:25:48 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	flood(char **arr, t_cub_data *data, int x, int y)
{
	if (x < 0 || x >= data->map->y_len || y < 0 || y >= data->map->x_len)
		return (false);
	if (arr[y][x] == VALIDATED_WALK_CHAR || arr[y][x] == BORDER_CHAR)
		return (true);
	if (arr[y][x] == WHITE_SPACE_CHAR)
		return (false);
	arr[y][x] = VALIDATED_WALK_CHAR;
	return (flood(arr, data, x + 1, y) \
			&& flood(arr, data, x - 1, y) \
			&& flood(arr, data, x, y + 1) \
			&& flood(arr, data, x, y - 1));
}

static bool	loop_map(char **arr, int wid, int hei)
{
	int	x;
	int	y;

	y = -1;
	while (++y < hei)
	{
		x = -1;
		while (++x < wid)
			if (arr[y][x] == WALK_CHAR)
				return (false);
	}
	return (true);
}

bool	check_map(char **arr, t_cub_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->x_len)
	{
		x = 0;
		while (x < data->map->y_len)
		{
			while (arr[y][x] != WALK_CHAR && x < data->map->y_len)
				x++;
			if (arr[y][x] == WALK_CHAR)
				if (!flood(arr, data, x, y))
					return (false);
		}
	}
	if (loop_map(arr, data->map->y_len, data->map->x_len))
		return (true);
	return (false);
}
