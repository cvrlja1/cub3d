/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:00:10 by nightcore         #+#    #+#             */
/*   Updated: 2025/04/01 15:43:46 by nicvrlja         ###   ########.fr       */
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

static void	try_destory_mlx_img(void *mlx_ptr, t_image *img)
{
	if (img == NULL)
		return ;
	mlx_destroy_image(mlx_ptr, img->mlx_img);
	free(img);
}

static void	free_textures(t_textures *textures, void *mlx_ptr)
{
	if (textures == NULL)
		return ;
	if (textures->paths != NULL)
	{
		if (textures->paths->no != NULL)
			free(textures->paths->no);
		if (textures->paths->ea != NULL)
			free(textures->paths->ea);
		if (textures->paths->so != NULL)
			free(textures->paths->so);
		if (textures->paths->we != NULL)
			free(textures->paths->we);
	}
	(void) mlx_ptr;
	// the textures have to be properly detroyes/freed here
	if (textures->no != NULL)
		try_destory_mlx_img(mlx_ptr, textures->no->mlx_img);
	if (textures->ea != NULL)
		try_destory_mlx_img(mlx_ptr, textures->ea->mlx_img);
	if (textures->so != NULL)
		try_destory_mlx_img(mlx_ptr, textures->so->mlx_img);
	if (textures->we != NULL)
		try_destory_mlx_img(mlx_ptr, textures->we->mlx_img);
	free(textures);
	textures = NULL;
}

void	free_cub(t_cub_data *data)
{
	if (data == NULL)
		return ;
	free_textures(data->textures, data->mlx);
	try_destory_mlx_img(data->mlx, data->img);
	if (data->mlx != NULL && data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map(data->map);
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
