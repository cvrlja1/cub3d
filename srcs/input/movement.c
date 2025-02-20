/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:49:13 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/20 12:32:47 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	change_mov_dir(t_mov_vars *mov, int key, int dir)
{
	if (key == FORWARD)
	{
		mov->dir_x += dir;
	}
	else if (key == BACKWARD)
	{
		mov->dir_x -= dir;
	}
	else if (key == RIGHT)
	{
		mov->dir_y += dir;
	}
	else if (key == LEFT)
	{
		mov->dir_y -= dir;
	}
}

static void	check_collision(t_player *player, t_map *map, t_vector2 *dir)
{
	int			tmp;

	tmp = (int)(player->x + dir->x);
	if (tmp >= map->x_len || tmp < 0)
		dir->x = 0;
	else if (map->arr[tmp][(int) player->y] != '0')
		dir->x = 0;
	tmp = (int)(player->y + dir->y);
	if (tmp >= map->y_len || tmp < 0)
		dir->y = 0;
	else if (map->arr[(int) player->x][tmp] != '0')
		dir->y = 0;
}

static void	get_move_direction(t_vector2 *vect, t_cub_data *data)
{
	normalize_vector2(vect);
	rotate_vector2(vect, data->player->rot);
	vect->x *= PLAYER_MOVE_MULT;
	vect->y *= PLAYER_MOVE_MULT;
	if (data->player->mov->is_spriting)
	{
		vect->x *= 3;
		vect->y *= 3;
		data->player->fov_mult = 1.05;
	}
	else
		data->player->fov_mult = 1;
	check_collision(data->player, data->map, vect);
}

void	move_player(t_cub_data *data)
{
	t_vector2	vect;

	vect.x = data->player->mov->dir_x;
	vect.y = data->player->mov->dir_y;
	if (vect.x == 0 && vect.y == 0)
		return ;
	get_move_direction(&vect, data);
	data->player->x += vect.x;
	data->player->y += vect.y;
}
