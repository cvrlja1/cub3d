/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:22:00 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/04 05:41:18 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	init(t_ray *ray, t_vector2 plr)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (plr.x - (int) plr.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = ((ray->map_x + 1) - plr.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (plr.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.y = ((ray->map_y + 1) - plr.y) * ray->delta_dist.y;
	}
}

void	dda(t_ray *ray, t_player_info *inf, char **map)
{
	init(ray, inf->player_pos);
	while (ray->hit == false)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->step_x;
			ray->side = EA_WE;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_y += ray->step_y;
			ray->side = NO_SO;
		}
		if (ray->map_x >= WINDOW_WIDTH || ray->map_y >= WINDOW_HEIGHT)
			return ;
		if (map[ray->map_x][ray->map_y] == '1')
		{
			ray->hit = true;
		}
	}
}