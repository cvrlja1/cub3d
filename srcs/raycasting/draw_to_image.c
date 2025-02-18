/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:47:27 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/04 05:28:56 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static int	get_line_height(t_ray *ray)
{
	double	distance;
	int		height;

	if (ray->side == NO_SO)
		distance = ray->side_dist.x - ray->delta_dist.x;
	else
		distance = ray->side_dist.y - ray->delta_dist.y;
	height = (int) WINDOW_HEIGHT / distance;
	return (height);
}

void	draw_vertical_line(t_ray *ray, t_image *img, int x_pos)
{
	int	line_height;
	int	start;
	int	end;

	line_height = get_line_height(ray);
	start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT - 1;
	while (start < end)
	{
		put_pixel_on_img(img, x_pos, start, 0x777777);
		start++;
	}
}

void	fill_image_background(t_cub_data *data)
{
	int	color;
	int	x;
	int y;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (y < WINDOW_HEIGHT / 2)
				color = data->textures->ceil_clr;
			else
				color = data->textures->flr_clr;
			put_pixel_on_img(data->img, x, y, color);
			y++;
		}
		x++;
	}
}
