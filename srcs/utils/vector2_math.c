/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:41:41 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/04 15:57:55 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	rotate_vector2(t_vector2 *vect, double rad)
{
	float	x;
	float	y;

	x = cos(rad) * vect->x + -sin(rad) * vect->x;
	y = sin(rad) * vect->y + cos(rad) * vect->y;
	vect->x = x;
	vect->y = y;
}

// maybe change to quicker aproximation algorithm...
void	normalize_vector2(t_vector2 *vect)
{
	float	len;

	len = sqrt((vect->x * vect->x) + (vect->y * vect->y));
	vect->x = vect->x / len;
	vect->y = vect->y / len;
}
