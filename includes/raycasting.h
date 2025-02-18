/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:25:04 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/18 16:21:40 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

/* --------> Includes <-------- */

# include "cub3d.h"

// ############### //
//   Definitions   //
// ############### //

/* --------> Structures <-------- */

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef enum e_side
{
	NO_SO,
	EA_WE
}	t_side;

typedef struct s_ray
{
	t_vector2	*start;
	float		rot;
	t_vector2	*dir;
	t_vector2	*step_size;
	t_vector2	*length;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	t_side		side;
	bool		hit;
}	t_ray;

/* --------> Functions <-------- */

void	draw_vertical_line(t_ray *ray, t_image *img, int x_pos);
void	fill_image_background(t_cub_data *data);
void	dda(t_ray *ray, t_map *map);

void	rotate_vector2(t_vector2 *vect, double rad);
void	normalize_vector2(t_vector2 *vect);

#endif