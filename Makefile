NAME = cub3D
CC = cc
CFLAGS =  -I./inc -Wall -Werror -Wextra
LDFLAGS = -Lmlx -lmlx -lXext -lX11 -lm
SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR	:= 	./inc/libft
LIBFT		:= 	$(LIBFT_DIR)/libft.a
SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/error_handling.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

.c.o:		
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

my: all myclean

.PHONY: all clean fclean re