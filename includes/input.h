/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:39:23 by tluegham          #+#    #+#             */
/*   Updated: 2025/02/18 17:02:35 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

/* --------> Includes <-------- */

# include "cub3d.h"
# include "X11/keysym.h"

// ############### //
//   Definitions   //
// ############### //

/* --------> Structures <-------- */

/* --------> Functions <-------- */

void	hande_player_input(int keycode, t_cub_data *data);
void	rotate_player(int keycode, t_player *player);

#endif