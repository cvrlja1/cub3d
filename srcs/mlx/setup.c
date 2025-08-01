/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:12:37 by nightcore         #+#    #+#             */
/*   Updated: 2025/07/01 13:38:41 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_hooks(t_cub_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, on_key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, on_key_released, data);
	mlx_hook(data->win, 17, 0, (int (*)(void *))close_cub_mlx, data);
	mlx_loop_hook(data->mlx, update, data);
}

bool	try_mlx_setup(t_cub_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error(MLX_INIT_ERR), false);
	data->win = \
		mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
	if (data->win == NULL)
		return (print_error(MLX_WIN_ERR), false);
	data->img = create_image(data->mlx);
	if (data->img == NULL)
		return (false);
	mlx_do_key_autorepeatoff(data->mlx);
	if (!load_textures(data))
		return (false);
	setup_hooks(data);
	return (true);
}
