/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:47:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/04/01 16:37:35 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	setup_ray(t_ray *ray, t_cub_data *data, int x)
{
	float	tmp;

	ray->relative_rot = (2 * x / (float) WINDOW_WIDTH - 1) * \
							FOV_RAD_HALF * data->player->fov_mult;
	ray->rot = data->player->rot + ray->relative_rot;
	ray->dir->x = cos(ray->rot);
	ray->dir->y = sin(ray->rot);
	ray->map_x = (int) ray->start->x;
	ray->map_y = (int) ray->start->y;
	tmp = ray->dir->y / ray->dir->x;
	ray->step_size->x = sqrt(1 + tmp * tmp);
	tmp = ray->dir->x / ray->dir->y;
	ray->step_size->y = sqrt(1 + tmp * tmp);
	ray->hit = false;
	memset(ray->length, 0, sizeof(t_vector2));
}

void	raycast_image(t_cub_data *data)
{
	t_ray	ray;
	int		x;
	t_image	*texture;

	x = 0;
	texture = NULL;
	ray.start = &(t_vector2){.x = data->player->x, .y = data->player->y};
	ray.dir = &(t_vector2){.x = 0, .y = 0};
	ray.step_size = &(t_vector2){.x = 0, .y = 0};
	ray.length = &(t_vector2){.x = 0, .y = 0};
	fill_image_background(data);
	while (x < WINDOW_WIDTH)
	{
		setup_ray(&ray, data, x);
		dda(&ray, data->map);
		if (!ray.hit)
			continue ;
		if (ray.side == NO_SO && ray.dir->y > 0)
			texture = data->textures->no;
		else if (ray.side == NO_SO && ray.dir->y < 0)
			texture = data->textures->so;
		else if (ray.side == EA_WE && ray.dir->x > 0)
			texture = data->textures->ea;
		else if (ray.side == EA_WE && ray.dir->x < 0)
			texture = data->textures->we;
		draw_vertical_line(&ray, data->img, x, texture);
		x++;
	}
}
