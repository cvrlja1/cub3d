/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:42:27 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/03/26 22:40:51 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*load_texture(char *filename, t_cub_data *data)
{
	t_image	*img;

	img = ft_calloc(1, sizeof(t_image));
	if (img == NULL)
	{
		print_error(MALLOC_ERR);
		return (NULL);
	}
	img->mlx_img = \
		mlx_xpm_file_to_image(data->mlx, filename, &img->width, &img->height);
	if (!img->mlx_img)
	{
		print_error(MLX_ERR);
		return (NULL);
	}
	img->mlx_addr = \
		mlx_get_data_addr(img->mlx_img, &img->bpp, &img->size_line, &img->bpp);
	if (!img->mlx_addr)
	{
		print_error(MLX_ERR);
		return (NULL);
	}
	return (img);
}


int get_pixel_color(t_image *texture, int x, int y)
{
  	char	*pixel_addr;

	pixel_addr = texture->mlx_addr + (y * texture->size_line) + (x * (texture->bpp / 8));
	return (*(int *)pixel_addr);
}
