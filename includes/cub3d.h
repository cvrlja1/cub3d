/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:04:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/02 22:51:09 by nightcore        ###   ########.fr       */
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

# define MALLOC_ERR "Memory allocation error!"

/* --------> Structures <-------- */

typedef struct s_player
{
	float	x;
	float	y;
	float	rot;
	
}	t_player;

// maybe incude textures here, ceiling and floor color
// needs a more fitting name, can't think of any right now
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