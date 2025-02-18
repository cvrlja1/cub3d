/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:47:27 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 16:08:56 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static int	get_line_height(t_ray *ray)
{
	float	distance;
	int		height;

	if (ray->side == EA_WE)
		distance = ray->length->x - ray->step_size->x;
	else
		distance = ray->length->y - ray->step_size->y;
	height = (int) WINDOW_HEIGHT / distance;
	return (height);
}

void	draw_vertical_line(t_ray *ray, t_image *img, int x_pos)
{
	int	line_height;
	int	start;
	int	end;
	int	color;

	line_height = get_line_height(ray);
	start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT - 1;
	color = 0x222222;
	if (ray->side == NO_SO)
		color /= 2;
	while (start < end)
	{
		put_pixel_on_img(img, x_pos, start, color);
		start++;
	}
}

void	fill_image_background(t_cub_data *data)
{
	int	color;
	int	x;
	int	y;

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
