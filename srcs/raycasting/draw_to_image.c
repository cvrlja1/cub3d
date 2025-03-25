/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:47:27 by nightcore         #+#    #+#             */
/*   Updated: 2025/03/25 14:32:14 by nicvrlja         ###   ########.fr       */
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
int get_pixel_from_texture(t_image *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->mlx_addr + (y * texture->size_line + x * (texture->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

void draw_vertical_line(t_ray *ray, t_image *img, int x_pos, t_image *wall)
{
	int		line_height;
	int		start;
	int		end;
	int		y;
	int		tex_x;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;
	float	wall_x;

	if (ray->side == NO_SO)
		wall_x = ray->start->x + ray->length->x;
	else
		wall_x = ray->start->y + ray->length->y;
	wall_x -= floor(wall_x);

	tex_x = (int)(wall_x * (double)wall->width);
	if ((ray->side == NO_SO && ray->dir->x > 0) || 
	    (ray->side == EA_WE && ray->dir->y < 0))
		tex_x = wall->width - tex_x - 1;
 
	tex_x = tex_x % wall->width;
	line_height = get_line_height(ray);
	start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT - 1;

	step = 1.0 * wall->height / line_height;
	tex_pos = (start - WINDOW_HEIGHT / 2 + line_height / 2) * step;

	y = start;
	while (y <= end)
	{
		tex_y = (int)tex_pos & (wall->height - 1);
		tex_pos += step;

		color = get_pixel_from_texture(wall, tex_x, tex_y);

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
