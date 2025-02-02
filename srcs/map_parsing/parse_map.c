/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:15:15 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/02 22:56:47 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	fill_map_arr(char **map, int fd)
{
	int	i;
	int	j;

	i = 0;
	// while no EOF
	while (i)
	{
		j = 0;
		// while no nl
		while (j)
		{
			(void) fd;
			map[i][j] = 'Y';
			j++;
		}
		i++;
	}
}

static void	free_map_arr_malloc_fail(char **map)
{
	int	i;

	print_error(MALLOC_ERR);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
}

static char	**create_map_arr(t_map_size ms)
{
	char	**map;
	int		i;

	map = (char **) ft_calloc(ms.x + 1, sizeof(char *));
	if (map == NULL)
		return (map);
	i = 0;
	while (i < ms.x)
	{
		map[i] = (char *) ft_calloc(ms.y + 1, sizeof(char));
		if (map[i] == NULL)
			return (free_map_arr_malloc_fail(map), NULL);
		i++;
	}
	return (map);
}

static t_map_size	get_map_size(int fd)
{
	t_map_size	ms;
	int			i;
	int			j;

	// read the whole 
	(void) fd;
	(void) i;
	(void) j;
	ms.x = 0;
	ms.y = 0;
	return (ms);
}

char	**get_map_arr(int fd)
{
	t_map_size	ms;
	char		**arr;

	ms = get_map_size(fd);
	if (ms.x < 0 || ms.y < 0)
		return (NULL);
	arr = create_map_arr(ms);
	if (arr == NULL)
		return (arr);
	fill_map_arr(arr, fd);
	return (arr);
}
