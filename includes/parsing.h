/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:24:57 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 02:27:07 by nightcore        ###   ########.fr       */
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
# define MAP_EXT_ERR "Invalid map! File extension must be of type *.cub!"
# define MAP_PATH_ERR "Invalid map! Map cannot be opened!"
# define MAP_NL_ERR "Invalid map! There is an empty line in the map!"
# define MAP_CHAR_ERR "Invalid map! There is an invalid character used the map!"
# define UPPER_SPWN_ERR "Invalid map! Only one player spawn point allowed!"
# define LESSER_SPWN_ERR "Invalid map! There is no player spawn point. \
Use 'N', 'E', 'S' or 'W'!"
# define ACCEPTED_CHARS "01 \t\nNESW"

/* --------> Structures <-------- */

typedef struct s_map_info
{
	int		x;
	int		y;
	char	**map;
	int		spawn_count;
}	t_map_info;

/* --------> Functions <-------- */

bool		is_player_spawn(char c);
char		**get_map_arr(t_cub_data *data, char *path, int fd, int bytes_read);
t_map_info	get_map_infos(int fd, int *fd_read_count);
bool		try_fill_map_arr(t_cub_data *data, char **map, int fd);

#endif