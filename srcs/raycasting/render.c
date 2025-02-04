/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:47:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/04 17:43:19 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

// static t_player_info	get_player_info(t_player *player)
// {
// 	t_player_info	inf;

// 	inf.player_pos.x = player->x;
// 	inf.player_pos.x = player->y;
// 	inf.dir = (t_vector2){.x = -1, .y = 0};
// 	rotate_vector2(&inf.dir, player->rot);
// 	inf.plane = (t_vector2){.x = 0, .y = 0.66};
// 	// calculate this with FOV later on...
// 	return (inf);
// }

// static void	init_ray(t_ray *ray, t_player_info *inf, int x)
// {
// 	double	camera_x;

// 	//ft_memset(&ray, 0, sizeof(ray));
// 	camera_x = 2 * x / (double) WINDOW_WIDTH - 1;
// 	ray->dir.x = inf->dir.x + inf->plane.x * camera_x;
// 	ray->dir.y = inf->dir.y + inf->plane.y * camera_x;
// 	ray->side_dist.x = 0;
// 	ray->side_dist.y = 0;
// 	//ray.delta_dist.x = (ray.dir.x == 0) ? 1e30 : abs((int) (1 / ray.dir.x));
// 	//ray.delta_dist.y = (ray.dir.y == 0) ? 1e30 : abs((int) (1 / ray.dir.y));
// 	ray->delta_dist.x = abs((int) (1 / ray->dir.x));
// 	ray->delta_dist.y = abs((int) (1 / ray->dir.y));
// 	ray->hit = false;
// 	ray->map_x = (int) inf->player_pos.x;
// 	ray->map_x = (int) inf->player_pos.y;
// }

void raycast_image(t_cub_data *data)
{
	// t_player_info	inf;
	// t_ray			ray;

	// fill_image_background(data);
	// inf = get_player_info(data->player);
	// for (int x = 0; x < WINDOW_WIDTH; x++)
	// {
	// 	init_ray(&ray, &inf, x);
	// 	dda(&ray, &inf, data->map->arr);
	// 	draw_vertical_line(&ray, data->img, x);
	// }

	t_vector2	plane;
	t_vector2	player_dir;
	t_vector2	ray_start;

	ray_start = (t_vector2){.x = data->player->x, .y = data->player->y};
	player_dir = (t_vector2){.x = cos(data->player->rot), .y = sin(data->player->rot)};
	plane = (t_vector2) {.x = 0, .y = 0.66};
	rotate_vector2(&plane, data->player->rot);

	fill_image_background(data);
	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		// DDA
		int			map_x;
		int			map_y;
		t_vector2	ray_dir;
		t_vector2	ray_step_size;
		float		tmp_val;

		tmp_val = 2 * x / (float) WINDOW_WIDTH - 1;
		ray_dir.x = player_dir.x + plane.x * tmp_val;
		ray_dir.y = player_dir.y + plane.y * tmp_val;
		map_x = (int)ray_start.x;
		map_y = (int)ray_start.y;
		

		ray_step_size.x = sqrt(1 + (ray_dir.y / ray_dir.x) * (ray_dir.y / ray_dir.x));
		ray_step_size.y = sqrt(1 + (ray_dir.x / ray_dir.y) * (ray_dir.x / ray_dir.y));
		// even if there is division by 0, we are using IEEE floats,
		// which turns the result into INFINITY.
		// In the alorithm any number will be smaller then INIFITY, so this works.

		t_vector2	ray_length;
		int			step_x;
		int			step_y;

		if (ray_dir.x < 0)
		{
			step_x = -1;
			ray_length.x = (ray_start.x - (float)map_x) * ray_step_size.x;
		}
		else
		{
			step_x = 1;
			ray_length.x = (((float)map_x + 1) - ray_start.x) * ray_step_size.x;
		}
		if (ray_dir.y < 0)
		{
			step_y = -1;
			ray_length.y = (ray_start.y - (float)map_y) * ray_step_size.y;
		}
		else
		{
			step_y = 1;
			ray_length.y = (((float)map_y + 1) - ray_start.y) * ray_step_size.y;
		}

		bool has_hit;
		t_map *m;
		int side;

		has_hit = false;
		m = data->map;

		while (!has_hit)
		{
			if (ray_length.x < ray_length.y)
			{
				map_x += step_x;
				ray_length.x += ray_step_size.x;
				side = 0;
			}
			else
			{
				map_y += step_y;
				ray_length.y += ray_step_size.y;
				side = 1;
			}
			if (map_x >= m->x_len || map_x < 0 || map_y >= m->y_len || map_y < 0)
				break;
			if (m->arr[map_x][map_y] == '1')
				has_hit = true;
		}
		if (!has_hit)
		{
			printf("failed to hit...\n");
			return;
		}
		// printf("hit at: [%d][%d], dist: %f\n", map_x, map_y, sqrt(ray_length.x * ray_length.x + ray_length.y * ray_length.y));

		float perp_wall_dist;

		if (side == 0)
			perp_wall_dist = (ray_length.x - ray_step_size.x);
		else
			perp_wall_dist = (ray_length.y - ray_step_size.y);

		int line_height;
		int start;
		int end;

		line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
		start = -line_height / 2 + WINDOW_HEIGHT / 2;
		if (start < 0)
			start = 0;
		end = line_height / 2 + WINDOW_HEIGHT / 2;
		if (end >= WINDOW_HEIGHT)
			start = WINDOW_HEIGHT - 1;

		int color = 0x222222;
		if (side == 1)
			color /= 2;
		while (start < end)
		{
			put_pixel_on_img(data->img, x, start, color);
			start++;
		}
	}
}
