/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:47:27 by nightcore         #+#    #+#             */
/*   Updated: 2025/04/08 12:20:15 by nicvrlja         ###   ########.fr       */
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

static int	get_pixel_from_texture(t_image *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->mlx_addr
		+ (y * texture->size_line + x * (texture->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

static void	setup_draw(t_ray *ray, t_line *line, t_image *texture)
{
	if (ray->side == EA_WE)
		line->wall_dist = ray->length->x - ray->step_size->x;
	else
		line->wall_dist = ray->length->y - ray->step_size->y;
	if (ray->side == NO_SO)
		line->wall_x = ray->start->x + line->wall_dist * ray->dir->x;
	else
		line->wall_x = ray->start->y + line->wall_dist * ray->dir->y;
	line->wall_x -= floor(line->wall_x);
	line->tex_x = (int)(line->wall_x * (double)texture->width);
	if ((ray->side == NO_SO && ray->dir->y > 0)
		|| (ray->side == EA_WE && ray->dir->x < 0))
		line->tex_x = texture->width - line->tex_x - 1;
	line->line_height = get_line_height(ray);
	line->start = -line->line_height / 2 + WINDOW_HEIGHT / 2;
	if (line->start < 0)
		line->start = 0;
	line->end = line->line_height / 2 + WINDOW_HEIGHT / 2;
	if (line->end >= WINDOW_HEIGHT)
		line->end = WINDOW_HEIGHT - 1;
	line->step = 1.0 * texture->height / line->line_height;
	line->tex_pos = (line->start - WINDOW_HEIGHT / 2 + line->line_height / 2)
		* line->step;
	line->y = line->start;
}

void	draw_vert_line(t_ray *ray, t_image *img, int x_pos, t_image *texture)
{
	t_line	line;

	setup_draw(ray, &line, texture);
	while (line.y <= line.end)
	{
		line.tex_y = (int)line.tex_pos & (texture->height - 1);
		line.tex_pos += line.step;
		line.color = get_pixel_from_texture(texture, line.tex_x, line.tex_y);
		put_pixel_on_img(img, x_pos, line.y, line.color);
		line.y++;
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
