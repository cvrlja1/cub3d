/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:41:41 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/04 05:00:34 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	rotate_vector2(t_vector2 *vect, double rad)
{
	double	x;
	double	y;

	x = cos(rad) * vect->x + -sin(rad) * vect->x;
	y = sin(rad) * vect->y + cos(rad) * vect->y;
	vect->x = x;
	vect->y = y;
}
