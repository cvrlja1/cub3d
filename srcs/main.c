/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:03:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/07/01 13:39:25 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	debug_print_map(t_map *map)
// {
// 	char	c;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	printf("Showing map:\n\n");
// 	while (map->arr[i] != NULL)
// 	{
// 		j = 0;
// 		while (j < map->y_len)
// 		{
// 			c = map->arr[i][j++];
// 			if (c == '\0')
// 				c = ' ';
// 			write(1, &c, 1);
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }

// static void	debug_textures(t_textures *textures)
// {
// 	if (textures == NULL)
// 		return ;
// 	printf(" Ceiling color: %X\n", textures->ceil_clr);
// 	printf(" Floor color:   %X\n", textures->flr_clr);
// 	printf(" NO path:       %s\n", textures->paths->no);
// 	printf(" EA path:       %s\n", textures->paths->ea);
// 	printf(" SO path:       %s\n", textures->paths->so);
// 	printf(" WE path:       %s\n", textures->paths->we);
// }

int	main(int argc, char **argv)
{
	t_cub_data	data;

	ft_memset(&data, 0, sizeof(t_cub_data));
	if (!try_initialization(argc, argv, &data))
		return (1);
	if (!try_mlx_setup(&data))
		close_cub(&data, 1);
	mlx_loop(data.mlx);
	return (0);
}
