/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:03:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/03 22:08:22 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_print_map(t_map *map)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	printf("Showing map:\n\n");
	while (map->arr[i] != NULL)
	{
		j = 0;
		while (j < map->y_len)
		{
			c = map->arr[i][j++];
			if (c == '\0')
				c = ' ';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

static void	debug_textures(t_textures *textures)
{
	if (textures == NULL)
		return ;
	printf(" Ceiling color: %X\n", textures->ceil_clr);
	printf(" Floor color:   %X\n", textures->flr_clr);
	printf(" NO path:       %s\n", textures->no_path);
	printf(" EA path:       %s\n", textures->ea_path);
	printf(" SO path:       %s\n", textures->so_path);
	printf(" WE path:       %s\n", textures->we_path);
}

int	main(int argc, char **argv)
{
	t_cub_data	data;

	ft_memset(&data, 0, sizeof(t_cub_data));
	if (!try_initialization(argc, argv, &data))
		return (1);
	debug_print_map(data.map);
	debug_textures(data.textures);
	if (!try_mlx_setup(&data))
		close_cub(&data, 1);
	mlx_loop(data.mlx);
	return (0);
}
