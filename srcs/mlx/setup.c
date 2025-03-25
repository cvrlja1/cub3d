/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:12:37 by nightcore         #+#    #+#             */
/*   Updated: 2025/03/25 12:45:41 by nicvrlja         ###   ########.fr       */
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
static int	load_images(t_cub_data *data)
{
	data->walls = (t_image *) ft_calloc(1, sizeof(t_image));
	if (!data->walls)
		return (0);
	data->walls->mlx_img = mlx_xpm_file_to_image(data->mlx, "./assets/brick.xpm", &data->walls->width, &data->walls->height);
	if (!data->walls->mlx_img)
		return (printf("nicht gefunden"), 0);
	data->walls->mlx_addr = (char *) mlx_get_data_addr(data->walls->mlx_img, &data->walls->bpp, &data->walls->size_line, &data->walls->endian);
	if (!data->walls->mlx_addr)
		return (0);
	return (1);
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
	if (!load_images(data))
		return (false);
	setup_hooks(data);
	return (true);
}
