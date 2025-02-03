/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:09:55 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 23:26:44 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/keysym.h>

void	rotate_player(int keycode, t_player *player)
{
	const int	rot_amount = 10;
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

void	hande_player_input(int keycode, t_cub_data *data)
{
	if (keycode == XK_Left || keycode == XK_Right)
		rotate_player(keycode, data->player);
}

