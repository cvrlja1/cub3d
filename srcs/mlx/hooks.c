/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:34:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 18:23:28 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	on_key_pressed(int keycode, void *data)
{
	if (keycode == XK_Escape)
		close_cub(data, 0);
	if (keycode == XK_Left || keycode == XK_Right)
		rotate_player(keycode, ((t_cub_data *) data)->player);
	printf("pressed key %d\n", keycode);
	return (0);
}

int	on_key_released(int keycode, void *data)
{
	(void) keycode;
	(void) data;
	printf("released key %d\n", keycode);
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
	raycast_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->mlx_img, 0, 0);
	return (0);
}
