/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:03:41 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 18:26:34 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_on_img(t_image *img, int x, int y, int color)
{
	char	*pixel_addr;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel_addr = img->mlx_addr + img->size_line * y + img->bpp / 8 * x;
	*(int *) pixel_addr = color;
}

t_image	*create_image(void *mlx_ptr)
{
	t_image	*img;
	void	*mlx_img;
	int		bpp;
	int		s_line;
	int		end;

	img = (t_image *) ft_calloc(1, sizeof(t_image));
	if (img == NULL)
		return (print_error(MALLOC_ERR), NULL);
	mlx_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (mlx_img == NULL)
		return (print_error(MLX_IMG_ERR), free(img), NULL);
	img->mlx_img = mlx_img;
	img->mlx_addr = (char *) mlx_get_data_addr(mlx_img, &bpp, &s_line, &end);
	img->bpp = bpp;
	img->size_line = s_line;
	img->endian = end;
	return (img);
}
