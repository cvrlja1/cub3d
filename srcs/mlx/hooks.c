/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:34:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 18:53:16 by nicvrlja         ###   ########.fr       */
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
	t_xpm *img = load_xpm("./textures/wall.xpm", data);
	raycast_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->mlx_img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, img->img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_destroy_image(data->mlx, img->img);
	free(img);
	return (0);
}
