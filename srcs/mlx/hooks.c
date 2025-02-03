/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:34:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 23:27:29 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/keysym.h>

int	key_hook(int keycode, t_cub_data *data)
{
	if (keycode == XK_Escape)
		close_cub(data, 0);
	hande_player_input(keycode, data);
	return (0);
}

int	close_cub_mlx(t_cub_data *data)
{
	close_cub(data, 0);
	return (0);
}

int	render(void *arg)
{
	t_cub_data	*data;

	data = (t_cub_data *) arg;
	raycast_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->mlx_img, 0, 0);
	return (0);
}
