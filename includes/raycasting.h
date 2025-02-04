/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:25:04 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/04 05:05:13 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

/* --------> Includes <-------- */

# include "cub3d.h"

// ############### //
//   Definitions   //
// ############### //

# define FOV = 90

/* --------> Structures <-------- */

typedef struct s_vector2
{
	double	x;
	double	y;
}	t_vector2;

typedef enum e_side
{
	NO_SO,
	EA_WE
}	t_side;

typedef struct s_ray
{
	t_vector2	dir;
	t_vector2	delta_dist;
	t_vector2	side_dist;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	t_side		side;
	bool		hit;
}	t_ray;

typedef struct s_player_info
{
	t_vector2	dir;
	t_vector2	plane;
	t_vector2	player_pos;
}	t_player_info;

/* --------> Functions <-------- */

void	draw_vertical_line(t_ray *ray, t_image *img, int x_pos);
void	fill_image_background(t_cub_data *data);
void	dda(t_ray *ray, t_player_info *inf, char **map);
void	rotate_vector2(t_vector2 *vect, double rad);

#endif