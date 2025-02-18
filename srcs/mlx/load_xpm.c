/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:42:27 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/18 18:52:13 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_xpm	*load_xpm(char *filename, t_cub_data *data)
{
	t_xpm	*img;

	img = ft_calloc(1, sizeof(t_xpm));
	img->img = mlx_xpm_file_to_image(data->mlx, filename, &img->width, &img->height);
	if (!img->img)
		return (NULL);
	return (img);
}