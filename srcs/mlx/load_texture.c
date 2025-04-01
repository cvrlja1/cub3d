/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:42:27 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/04/01 16:18:50 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	try_load_xpm(t_cub_data *data, t_image **texture, char *path)
{
	(*texture) = ft_calloc(1, sizeof(t_image));
	if (!*texture)
		return (false);
	(*texture)->mlx_img = mlx_xpm_file_to_image(data->mlx, path, &(*texture)->width, &(*texture)->height);
	if (!(*texture)->mlx_img)
		return (false);
	(*texture)->mlx_addr = mlx_get_data_addr((*texture)->mlx_img, &(*texture)->bpp, &(*texture)->size_line, &(*texture)->endian);
	if (!(*texture)->mlx_addr)
		return (false);
	return (true);
}

bool	load_textures(t_cub_data *data)
{
	if (!try_load_xpm(data, &data->textures->no, data->textures->paths->no))
		return (false);
	if (!try_load_xpm(data, &data->textures->ea, data->textures->paths->ea))
		return (false);
	if (!try_load_xpm(data, &data->textures->we, data->textures->paths->we))
		return (false);
	if (!try_load_xpm(data, &data->textures->so, data->textures->paths->so))
		return (false);
	return (true);
}

int get_pixel_color(t_image *texture, int x, int y)
{
  	char	*pixel_addr;

	pixel_addr = texture->mlx_addr + (y * texture->size_line) + (x * (texture->bpp / 8));
	return (*(int *)pixel_addr);
}
