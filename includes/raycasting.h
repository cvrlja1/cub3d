/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:25:04 by nightcore         #+#    #+#             */
/*   Updated: 2025/04/08 14:30:56 by nicvrlja         ###   ########.fr       */
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

typedef enum e_side
{
	NO_SO,
	EA_WE
}	t_side;

typedef struct s_ray
{
	t_vector2	*start;
	float		rot;
	float		relative_rot;
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

typedef struct s_line
{
	int		line_height;
	int		start;
	int		end;
	int		y;
	int		tex_x;
	int		tex_y;
	int		color;
	float	wall_x;
	double	step;
	double	tex_pos;
	float	wall_dist;
}	t_line;

/* --------> Functions <-------- */

void	draw_vert_line(t_ray *ray, t_image *img, int x_pos, t_image *wall);
void	fill_image_background(t_cub_data *data);
void	dda(t_ray *ray, t_map *map);

#endif