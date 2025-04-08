/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:09:55 by nightcore         #+#    #+#             */
/*   Updated: 2025/04/08 12:54:11 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void	rotate_player(int keycode, t_player *player)
{
	const int	rot_amount = 2;
	double		rot_degrees;

	rot_degrees = player->rot * 180 / M_PI;
	if (keycode == XK_Left)
		rot_degrees -= rot_amount;
	else
		rot_degrees += rot_amount;
	if (rot_degrees >= 360)
		rot_degrees -= 360;
	else if (rot_degrees < 0)
		rot_degrees += 360;
	player->rot = rot_degrees * M_PI / 180;
}

void	handle_release(int keycode, t_cub_data *data)
{
	if (keycode == XK_Left)
		data->player->rotate_left = false;
	else if (keycode == XK_Right)
		data->player->rotate_right = false;
	if (is_move_input(keycode))
		change_mov_dir(data->player->mov, keycode, -1);
	if (keycode == XK_Shift_L)
		data->player->mov->is_spriting = false;
}

void	update_rotation(t_cub_data *data)
{
	if (data->player->rotate_left)
		rotate_player(XK_Left, data->player);
	else if (data->player->rotate_right)
		rotate_player(XK_Right, data->player);
}

void	handle_press(int keycode, t_cub_data *data)
{
	if (keycode == XK_Left)
		data->player->rotate_left = true;
	else if (keycode == XK_Right)
		data->player->rotate_right = true;
	if (keycode == XK_Escape)
		close_cub(data, 0);
	if (is_move_input(keycode))
		change_mov_dir(data->player->mov, keycode, 1);
	if (keycode == XK_Shift_L)
		data->player->mov->is_spriting = true;
}
