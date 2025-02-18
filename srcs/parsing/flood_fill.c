/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:48:37 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/18 15:42:46 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool is_on_boundary(char **arr, int wid, int hei, int x, int y)
{
	if (arr[y][x] == WALK_CHAR && (x == 0 || x == wid - 1 || y == 0 || y == hei - 1))
		return (true);
	return (false);
}

static bool	is_valid(char **arr, int wid, int hei, int x, int y)
{
	if (x < 0 || x >= wid || y < 0 || y >= hei)
		return (false);
	if (arr[y][x] != WALK_CHAR)
		return (false);
	return (true);
}

static bool	flood(char **arr, int wid, int hei, int x, int y)
{
	static bool	check = true;
	if (is_on_boundary(arr, wid, hei, x, y) || arr[y][x] == '\0')
		return (false);
	if (!is_valid(arr, wid, hei, x, y))
		return (false);
	if (!check)
		return (false);
	arr[y][x] = '0';
	flood(arr, wid, hei, x + 1, y);
	flood(arr, wid, hei, x - 1, y);
	flood(arr, wid, hei, x, y + 1);
	flood(arr, wid, hei, x, y - 1);
	return (true);
}
bool	loop_map(char **arr, int wid, int hei)
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

static void	debug_print_map(char **arr, int wid, int hei)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	(void)hei;
	printf("Showing map:\n\n");
	while (arr[i] != NULL)
	{
		j = 0;
		while (j < wid)
		{
			c = arr[i][j++];
			if (c == '\0')
				c = ' ';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

bool	check_map(char **arr, int wid, int hei)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < hei)
	{
		x = 0;
		while (x < wid)
		{
			while (arr[y][x] != WALK_CHAR && x < wid)
				x++;
			if (arr[y][x] == WALK_CHAR)
				if (!flood(arr, wid, hei, x, y))
					return (false);
		}
	}
	if (loop_map(arr, wid, hei))
		return (true);
	debug_print_map(arr, wid, hei);
	return (false);
}

