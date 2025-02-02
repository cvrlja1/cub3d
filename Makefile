# -------------------------------------------------------------------
# VARIABLES
# -------------------------------------------------------------------

# Source file directories
SRCS_DIR			= ./srcs/
ERROR_DIR			= ./srcs/error/
PARSE_DIR			= ./srcs/map_parsing/

# Other directories
OBJS_DIR			= ./objs/
LIBFT_DIR			= ./libft/
INCLUDES_DIR		= ./includes/

# Source files
CFILES_ROOT			= main.c \

CFILES_ERROR		= error_handling.c \

CFILES_PARSE		= parse_arguments.c \

OBJ_FILES 			:= $(CFILES_ROOT:.c=.o) \
					   $(CFILES_ERROR:.c=.o) \
					   $(CFILES_PARSE:.c=.o)

OBJS				:= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Compilation variables
NAME				= cub3d
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

.PHONY: all clean fclean re

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
