/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:22:00 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 16:08:17 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	setup_dda(t_ray *ray)
{
	if (ray->dir->x < 0)
	{
		ray->step_x = -1;
		ray->length->x = \
			(ray->start->x - (float)ray->map_x) * ray->step_size->x;
	}
	else
	{
		ray->step_x = 1;
		ray->length->x = \
			(((float)ray->map_x + 1) - ray->start->x) * ray->step_size->x;
	}
	if (ray->dir->y < 0)
	{
		ray->step_y = -1;
		ray->length->y = \
			(ray->start->y - (float)ray->map_y) * ray->step_size->y;
	}
	else
	{
		ray->step_y = 1;
		ray->length->y = \
			(((float)ray->map_y + 1) - ray->start->y) * ray->step_size->y;
	}
}

void	dda(t_ray *ray, t_map *map)
{
	setup_dda(ray);
	while (!ray->hit)
	{
		if (ray->length->x < ray->length->y)
		{
			ray->map_x += ray->step_x;
			ray->length->x += ray->step_size->x;
			ray->side = EA_WE;
		}
		else
		{
			ray->map_y += ray->step_y;
			ray->length->y += ray->step_size->y;
			ray->side = NO_SO;
		}
		if (ray->map_x >= map->x_len || ray->map_x < 0)
			break ;
		if (ray->map_y >= map->y_len || ray->map_y < 0)
			break ;
		if (map->arr[ray->map_x][ray->map_y] == '1')
			ray->hit = true;
	}
}
