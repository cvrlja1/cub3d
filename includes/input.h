/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:39:23 by tluegham          #+#    #+#             */
/*   Updated: 2025/03/26 16:40:59 by nicvrlja         ###   ########.fr       */
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

# define FORWARD XK_w
# define LEFT XK_a
# define RIGHT XK_d
# define BACKWARD XK_s

# define PLAYER_MOVE_MULT 0.03

/* --------> Structures <-------- */

/* --------> Functions <-------- */

void	handle_release(int keycode, t_cub_data *data);
void	handle_press(int keycode, t_cub_data *data);
bool	is_move_input(int key);
void	change_mov_dir(t_mov_vars *mov, int key, int dir);
void	update_rotation(t_cub_data *data);

#endif