/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:47:27 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/20 21:18:35 by nightcore        ###   ########.fr       */
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
	distance = distance * cos(ray->relative_rot);
	height = (int) WINDOW_HEIGHT / distance;
	return (height);
}

void	draw_vertical_line(t_ray *ray, t_image *texture, t_image *img, int x_pos)
{
	int	line_height;
	int	start;
	int	end;
	int	color;
	int	tex_x;
	int	tex_y;
	int	y;
	float wall_x;

	// Calculate the height of the wall to determine the vertical scaling
	line_height = get_line_height(ray);

	// Calculate the start and end of the vertical line on the screen
	start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT - 1;
	color = 0x222222;
	if (ray->side == NO_SO)
		color /= 2;

	// Calculate the X texture coordinate based on the ray's fractional position
	if (ray->side == EA_WE)
		wall_x = ray->start->y - floor(ray->start->y);  // Fractional part of Y position for East-West walls
	else
		wall_x = ray->start->x - floor(ray->start->x);  // Fractional part of X position for North-South walls
	
	// Map this to the texture's width
	tex_x = (int)(wall_x * texture->width);

	// Iterate through the vertical line and apply the texture
	y = start;
	while (y <= end)
	{
		// Calculate the Y texture coordinate based on the vertical scaling of the line
		tex_y = ((y - start) * texture->height) / line_height;
		
		// Get the color from the texture and apply it to the image
		color = get_pixel_color(texture, tex_x, tex_y);
		put_pixel_on_img(img, x_pos, y, color);

		y++;
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
