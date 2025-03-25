/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:04:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/03/25 12:20:43 by nicvrlja         ###   ########.fr       */
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

// Fix for M_PI so vscode doesn't cry
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define FOV 66
# define FOV_RAD 1.1519173063
# define FOV_HALF 33
# define FOV_RAD_HALF 0.5759586532

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define PROGRAM_NAME "Genki Cub3D"

# define MALLOC_ERR "Memory allocation error!"
# define OPEN_FD_ERR "Failed to open a file descriptor!"
# define READ_FD_ERR "Failed to read from a file descriptor!"
# define MLX_INIT_ERR "Failed to initialize mlx!"
# define MLX_WIN_ERR "Failed to create mlx window!"
# define MLX_IMG_ERR "Failed to create mlx image!"

/* --------> Structures <-------- */

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_mov_vars
{
	int		dir_x;
	int		dir_y;
	bool	is_spriting;
}	t_mov_vars;

typedef struct s_player
{
	float		x;
	float		y;
	double		rot;
	double		fov_mult;
	t_mov_vars	*mov;
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
	int		width;
	int		height;
}	t_image;

typedef struct s_cub_data
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_image		*walls;
	t_player	*player;
	t_map		*map;
	t_textures	*textures;
}	t_cub_data;

/* --------> Functions <-------- */

// ############### //
//       Misc      //
// ############### //

bool	try_initialization(int argc, char **argv, t_cub_data *data);
void	raycast_image(t_cub_data *data);
void	move_player(t_cub_data *data);

// ############### //
//       Mlx       //
// ############### //

bool	try_mlx_setup(t_cub_data *data);
t_image	*create_image(void *mlx_ptr);
void	put_pixel_on_img(t_image *img, int x, int y, int color);
int		on_key_pressed(int keycode, void *data);
int		on_key_released(int keycode, void *data);
int		update(void *arg);

// ############### //
//      Utils      //
// ############### //

void	print_error(char *msg);
bool	is_whitespace(char c);
void	rotate_vector2(t_vector2 *vect, double rad);
void	normalize_vector2(t_vector2 *vect);
void	div_vector2(t_vector2 *vect, float div);
void	mult_vector2(t_vector2 *vect, float mult);

// ############### //
//  Close & Free   //
// ############### //

int		close_cub_mlx(t_cub_data *data);
void	close_cub(t_cub_data *data, int exit_code);
void	free_cub(t_cub_data *data);
void	free_map_arr(char **map);

#endif