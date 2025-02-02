/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:24:57 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/02 22:44:34 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* --------> Includes <-------- */

# include "cub3d.h"

// ############### //
//   Definitions   //
// ############### //

# define LESSER_ARG_ERR "Only one argument is allowed"
# define UPPER_ARG_ERR "Argument needed: a map in format *.cub"
# define INVALID_MAP_ERR "Invalid map!"
# define MAP_EXT_ERR INVALID_MAP_ERR " File extension must be of type *.cub!"
# define MAP_PATH_ERR INVALID_MAP_ERR " Map cannot be opened!"

/* --------> Structures <-------- */

typedef struct s_map_size
{
	int	x;
	int	y;
}	t_map_size;

/* --------> Functions <-------- */

char	**get_map_arr(int fd);

#endif