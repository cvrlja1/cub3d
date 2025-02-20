/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:00:10 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/19 21:09:25 by nightcore        ###   ########.fr       */
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

static void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->arr != NULL)
		free_map_arr(map->arr);
	free(map);
}

void	free_textures(t_textures *textures)
{
	if (textures == NULL)
		return ;
	if (textures->no_path != NULL)
		free(textures->no_path);
	if (textures->ea_path != NULL)
		free(textures->ea_path);
	if (textures->so_path != NULL)
		free(textures->so_path);
	if (textures->we_path != NULL)
		free(textures->we_path);
	free(textures);
	textures = NULL;
}

void	free_cub(t_cub_data *data)
{
	if (data == NULL)
		return ;
	if (data->mlx != NULL && data->img != NULL)
		mlx_destroy_image(data->mlx, data->img->mlx_img);
	if (data->mlx != NULL && data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->img != NULL)
		free(data->img);
	free_map(data->map);
	free_textures(data->textures);
	if (data->player != NULL)
	{
		if (data->player->mov != NULL)
			free(data->player->mov);
		free(data->player);
	}
}

void	close_cub(t_cub_data *data, int exit_code)
{
	mlx_do_key_autorepeaton(data->mlx);
	free_cub(data);
	exit(exit_code);
}
