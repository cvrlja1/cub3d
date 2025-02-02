/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:04:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/02 22:10:14 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* --------> Includes <-------- */

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

// ############### //
//   Definitions   //
// ############### //
# define LESSER_ARG_ERR "Only one argument is allowed"
# define UPPER_ARG_ERR "Argument needed: a map in format *.cub"
# define INVALID_MAP_ERR "Invalid map!"
# define MAP_EXT_ERR INVALID_MAP_ERR " File extension must be of type *.cub!"
# define MAP_PATH_ERR INVALID_MAP_ERR " Map cannot be opened!"

/* --------> Structures <-------- */

typedef struct s_player
{
	float	x;
	float	y;
	float	rot;
	
}	t_player;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_cub_data
{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
}	t_cub_data;


/* --------> Functions <-------- */


// ############### //
//     Parsing     //
// ############### //

bool	try_parse_map(int argc, char **argv, t_cub_data *data);

// ############### //
//     Errors      //
// ############### //

void	print_error(char *msg);

#endif