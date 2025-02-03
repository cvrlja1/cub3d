/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:47:29 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 23:08:51 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_vector2	get_player_dir_vector(t_player *player)
{
	t_vector2	vect;
	
	vect.x = cos(player->rot);
	vect.x = sin(player->rot);
	return (vect);
}

void	raycast_image(t_cub_data *data)
{
	t_player_info	inf;

	inf.dir_vect = get_player_dir_vector(data->player);
	inf.plane_vect = (t_vector2){.x = data->player->x, .y = data->player->y};
	(void) inf;
}