/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:47:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/04 05:42:10 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_player_info	get_player_info(t_player *player)
{
	t_player_info	inf;

	inf.player_pos.x = player->x;
	inf.player_pos.x = player->y;
	inf.dir = (t_vector2){.x = -1, .y = 0};
	rotate_vector2(&inf.dir, player->rot);
	inf.plane = (t_vector2){.x = 0, .y = 0.66};
	// calculate this with FOV later on...
	return (inf);
}

static void	init_ray(t_ray *ray, t_player_info *inf, int x)
{
	double	camera_x;

	//ft_memset(&ray, 0, sizeof(ray));
	camera_x = 2 * x / (double) WINDOW_WIDTH - 1;
	ray->dir.x = inf->dir.x + inf->plane.x * camera_x;
	ray->dir.y = inf->dir.y + inf->plane.y * camera_x;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	//ray.delta_dist.x = (ray.dir.x == 0) ? 1e30 : abs((int) (1 / ray.dir.x));
	//ray.delta_dist.y = (ray.dir.y == 0) ? 1e30 : abs((int) (1 / ray.dir.y));
	ray->delta_dist.x = abs((int) (1 / ray->dir.x));
	ray->delta_dist.y = abs((int) (1 / ray->dir.y));
	ray->hit = false;
	ray->map_x = (int) inf->player_pos.x;
	ray->map_x = (int) inf->player_pos.y;
}

void	raycast_image(t_cub_data *data)
{
	t_player_info	inf;
	t_ray			ray;

	fill_image_background(data);
	inf = get_player_info(data->player);
	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		init_ray(&ray, &inf, x);
		dda(&ray, &inf, data->map->arr);
		draw_vertical_line(&ray, data->img, x);
	}
}
