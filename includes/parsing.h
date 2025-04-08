/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:24:57 by nightcore         #+#    #+#             */
/*   Updated: 2025/04/08 14:30:36 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* --------> Includes <-------- */

# include "cub3d.h"

// ############### //
//    Error Defs   //
// ############### //

# define LESSER_ARG_ERR "Only one argument is allowed"
# define UPPER_ARG_ERR "Argument needed: a map in format *.cub"
# define PARSE_NL_ERR "Found a new line when trying to parse a idetifier!"
# define INVALID_ID_ERR "Invalid type identifier encountered!"
# define UPPER_ID_ERR "Only one identifier of a certain type allowed!"
# define LOWER_ID_ERR "Not all type identiiers are specified!"
# define LOWER_ID_ERR "Not all type identiiers are specified!"
# define CLR_RANGE_ERR "Colors must be a number and in range between [0,255]!"
# define CLR_COMMA_ERR "There must be a comma ',' between the RGB values!"
# define MAP_EXT_ERR "Invalid map! File extension must be of type *.cub!"
# define MAP_PATH_ERR "Invalid map! Map cannot be opened!"
# define MAP_NL_ERR "Invalid map! There is an empty line in the map!"
# define MAP_CHAR_ERR "Invalid map! There is an invalid character used the map!"
# define UPPER_SPWN_ERR "Invalid map! Only one player spawn point allowed!"
# define LESSER_SPWN_ERR "Invalid map! There is no player spawn point. \
Use 'N', 'E', 'S' or 'W'!"
# define FLOOD_FAIL "Invalid map! The map must be fully enclosed by walls."

// ############### //
//    Const Defs   //
// ############### //

# define ACCEPTED_MAP_CHARS "01 \t\nNESW"
# define NO_IDENTIFIER "NO"
# define EA_IDENTIFIER "EA"
# define SO_IDENTIFIER "SO"
# define WE_IDENTIFIER "WE"
# define F_IDENTIFIER "F"
# define C_IDENTIFIER "C"
# define WALK_CHAR 'X'

/* --------> Structures <-------- */

typedef enum e_identifier
{
	NO_ID = 0,
	NO = 1,
	EA = 2,
	SO = 3,
	WE = 4,
	C = 5,
	F = 6
}	t_identifier;

typedef struct s_id_info
{
	t_identifier	id;
	void			*ptr_ref;
}	t_id_info;

typedef struct s_map_info
{
	int		x;
	int		y;
	char	**map;
	int		spawn_count;
}	t_map_info;

/* --------> Functions <-------- */

bool		try_get_textures(t_cub_data *data, int fd, int *bytes_read);
t_id_info	find_id_info(t_textures *t, char *buf, int fd, int *bytes_read);
bool		is_valid_id_info(t_id_info *info);
bool		is_player_spawn(char c);
char		**get_map_arr(t_cub_data *data, char *path, int fd, int bytes_read);
t_map_info	get_map_infos(int fd, int *fd_read_count);
bool		try_fill_map_arr(t_cub_data *data, char **map, int fd);
bool		try_parse_color(t_id_info *inf, int fd, char *buf, int *byts_read);
bool		try_parse_texture(t_id_info *inf, int fd, char *buf, \
								int *byt_read);
bool		check_map(char **arr, t_cub_data *data);

#endif