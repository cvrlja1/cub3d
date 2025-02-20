/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:34:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/20 21:18:35 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	on_key_pressed(int keycode, void *data)
{
	handle_press(keycode, data);
	return (0);
}

int	on_key_released(int keycode, void *data)
{
	handle_release(keycode, data);
	return (0);
}

int	close_cub_mlx(t_cub_data *data)
{
	close_cub(data, 0);
	return (0);
}

int	update(void *arg)
{
	t_cub_data	*data;

	data = (t_cub_data *) arg;
	move_player(data);
	raycast_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->mlx_img, 0, 0);
	return (0);
}
