/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:48:37 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/04/08 14:30:13 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_on_boundary(char **arr, t_cub_data *data, int x, int y)
{
	if (arr[y][x] == WALK_CHAR && (x == 0 || x == data->map->y_len - 1
		|| y == 0 || y == data->map->x_len - 1))
		return (true);
	return (false);
}

static bool	is_valid(char **arr, t_cub_data *data, int x, int y)
{
	if (x < 0 || x >= data->map->y_len || y < 0 || y >= data->map->x_len)
		return (false);
	if (arr[y][x] != WALK_CHAR)
		return (false);
	return (true);
}

static bool	flood(char **arr, t_cub_data *data, int x, int y)
{
	static bool	check = true;

	if (is_on_boundary(arr, data, x, y) || arr[y][x] == '\0')
		check = false;
	if (!is_valid(arr, data, x, y))
		return (false);
	if (!check)
		return (false);
	arr[y][x] = '0';
	flood(arr, data, x + 1, y);
	flood(arr, data, x - 1, y);
	flood(arr, data, x, y + 1);
	flood(arr, data, x, y - 1);
	return (true);
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
