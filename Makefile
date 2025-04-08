# -------------------------------------------------------------------
# VARIABLES
# -------------------------------------------------------------------

# Source file directories
SRCS_DIR			= ./srcs/
ERROR_DIR			= ./srcs/error/
PARSE_DIR			= ./srcs/parsing/
UTILS_DIR			= ./srcs/utils/
RAYCASTING_DIR		= ./srcs/raycasting/
MLX_DIR				= ./srcs/mlx/
INPUT_DIR			= ./srcs/input/

# Other directories
OBJS_DIR			= ./objs/
LIBFT_DIR			= ./libft/
INCLUDES_DIR		= ./includes/

# Source files
CFILES_ROOT			= main.c \
					  close_program.c

CFILES_ERROR		= error_handling.c

CFILES_PARSE		= check_file.c \
					  init_textures.c \
					  get_identifiers.c \
					  parse_texture.c \
					  parse_color.c \
					  parse_map.c \
					  fill_map.c \
					  flood_fill.c \
					  get_map_infos.c

CFILES_RAYCAST		= render.c \
					  dda.c \
					  draw_to_image.c \

CFILES_MLX			= setup.c \
					  image.c \
					  load_texture.c \
					  hooks.c

CFILES_INPUT		= handle_player_input.c \
					  movement.c \
					  utils.c

CFILES_UTILS		= is_whitespace.c \
					  vector2_math.c \
					  free_map_arr.c

OBJ_FILES 			:= $(CFILES_ROOT:.c=.o) \
					   $(CFILES_ERROR:.c=.o) \
					   $(CFILES_UTILS:.c=.o) \
					   $(CFILES_RAYCAST:.c=.o) \
					   $(CFILES_MLX:.c=.o) \
					   $(CFILES_INPUT:.c=.o) \
					   $(CFILES_PARSE:.c=.o)

OBJS				:= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Compilation variables
NAME				= cub3D
CC 					= cc
CFLAGS 				= -Wall -Werror -Wextra -g
RM 					= rm -rf
LINKFLAGS			:= -L$(LIBFT_DIR) -lft -lmlx -lX11 -lXext -lm
INCLUDES			:= -I$(INCLUDES_DIR) -I$(LIBFT_DIR)
LIBFT				:= $(addprefix $(LIBFT_DIR), libft.a)

# -------------------------------------------------------------------
# RULES
# -------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKFLAGS)

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) objs

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

r:
	$(RM) objs
	make $(NAME)

.PHONY: all clean fclean re r

# -------------------------------------------------------------------
# OBJECT RULES
# -------------------------------------------------------------------
# // These have to be implemented for each directory in the project

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(OBJS_DIR)%.o: $(ERROR_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(OBJS_DIR)%.o: $(PARSE_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(OBJS_DIR)%.o: $(UTILS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(OBJS_DIR)%.o: $(RAYCASTING_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(OBJS_DIR)%.o: $(MLX_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(OBJS_DIR)%.o: $(INPUT_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@
