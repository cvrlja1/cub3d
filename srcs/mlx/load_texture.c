/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:42:27 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/20 19:57:41 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*load_texture(char *filename, t_cub_data *data)
{
	t_image	*img;

	img = ft_calloc(1, sizeof(t_image));
	img->mlx_img = mlx_xpm_file_to_image(data->mlx, filename, &img->width, &img->height);
	if (!img->mlx_img)
		return (NULL);
	img->mlx_addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->size_line, &img->bpp);
	if (!img->mlx_addr)
		return (NULL);
	return (img);
}


int get_pixel_color(t_image *texture, int x, int y)
{
  	char	*pixel_addr;

	pixel_addr = texture->mlx_addr + (y * texture->size_line) + (x * (texture->bpp / 8));
	return (*(int *)pixel_addr);
}
