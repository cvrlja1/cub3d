/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:25:04 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 22:57:34 by nightcore        ###   ########.fr       */
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
	double	x;
	double	y;
}	t_vector2;

typedef struct s_ray
{

}	t_ray;

typedef struct s_player_info
{
	t_vector2	dir_vect;
	t_vector2	plane_vect;
	t_vector2	player_pos;
}	t_player_info;

/* --------> Functions <-------- */

#endif