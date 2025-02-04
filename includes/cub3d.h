/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:04:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/02/04 15:51:47 by nightcore        ###   ########.fr       */
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
# include <math.h>
# include <mlx.h>

// ############### //
//   Definitions   //
// ############### //

# define MALLOC_ERR "Memory allocation error!"
# define OPEN_FD_ERR "Failed to open a file descriptor!"
# define READ_FD_ERR "Failed to read from a file descriptor!"
# define MLX_INIT_ERR "Failed to initialize mlx!"
# define MLX_WIN_ERR "Failed to create mlx window!"
# define MLX_IMG_ERR "Failed to create mlx image!"

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define PROGRAM_NAME "Genki Cub3D"

/* --------> Structures <-------- */

typedef struct s_player
{
	float	x;
	float	y;
	double	rot;
}	t_player;

typedef struct s_map
{
	char	**arr;
	int		x_len;
	int		y_len;
}	t_map;

typedef struct s_textures
{
	int		ceil_clr;
	int		flr_clr;
	char	*no_path;
	char	*ea_path;
	char	*so_path;
	char	*we_path;
}	t_textures;

typedef struct s_image
{
	void	*mlx_img;
	char	*mlx_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_cub_data
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_player	*player;
	t_map		*map;
	t_textures	*textures;
}	t_cub_data;

/* --------> Functions <-------- */

// ############### //
//       Misc      //
// ############### //

bool	try_initialization(int argc, char **argv, t_cub_data *data);
void	hande_player_input(int keycode, t_cub_data *data);
void	raycast_image(t_cub_data *data);

// ############### //
//       Mlx       //
// ############### //

bool	try_mlx_setup(t_cub_data *data);
t_image	*create_image(void *mlx_ptr);
void	put_pixel_on_img(t_image *img, int x, int y, int color);
int		key_hook(int keycode, t_cub_data *data);
int		render(void *arg);

// ############### //
//      Utils      //
// ############### //

void	print_error(char *msg);
bool	is_whitespace(char c);

// ############### //
//  Close & Free   //
// ############### //

int		close_cub_mlx(t_cub_data *data);
void	close_cub(t_cub_data *data, int exit_code);
void	free_cub(t_cub_data *data);
void	free_map_arr(char **map);

#endif