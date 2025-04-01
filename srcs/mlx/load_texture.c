/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:42:27 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/04/01 14:46:12 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_textures(t_cub_data *data)
{
	int		i;
	t_image	*prev;
	t_image	*current;
	char	*paths[4] = { data->textures->no_path, data->textures->ea_path, data->textures->so_path, data->textures->we_path };

	i = -1;
	data->walls = NULL;
	for (int i = 0; paths[0][i] != '\0'; i++) {
    printf("Character %d: '%c' (ASCII: %d)\n", i, paths[0][i], paths[0][i]);
}
	while (++i < 4)
	{
		current = (t_image *) ft_calloc(1, sizeof(t_image));
		if (!current)
			return (false);
		current->mlx_img = mlx_xpm_file_to_image(data->mlx, paths[i], &current->width, &current->height);
		if (!current->mlx_img)
			return (free(current), false);
		current->mlx_addr = (char *) mlx_get_data_addr(current->mlx_img, &current->bpp, &current->size_line, &current->endian);
		if (!current->mlx_addr)
			return (free(current), false);
		if (data->walls == NULL)
            data->walls = current;
        else
            prev->next = current;
		prev = current;
	}
	return (true);
}

int get_pixel_color(t_image *texture, int x, int y)
{
  	char	*pixel_addr;

	pixel_addr = texture->mlx_addr + (y * texture->size_line) + (x * (texture->bpp / 8));
	return (*(int *)pixel_addr);
}
