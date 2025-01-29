NAME = cub3D
CC = cc
CFLAGS =  -Imlx -I./inc -Wall -Werror -Wextra
SRC_DIR = ./src
INC_DIR = ./inc
SRC = $(SRC_DIR)/main.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

.c.o:		
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

my: all myclean

.PHONY: all clean fclean re