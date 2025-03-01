CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
B_NAME = so_long_bonus
LIBS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

SRC = get_next_line.c get_next_line_utils.c main.c bfs.c bfs_utils.c is_valid.c mlx_part.c moves.c init.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = bonus/main_bonus.c bonus/bfs_bonus.c bonus/bfs_utils_bonus.c bonus/is_valid_bonus.c \
            bonus/mlx_part_bonus.c bonus/moves_bonus.c bonus/init_bonus.c bonus/init2_bonus.c \
            bonus/cleanexit_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBS) -o $(B_NAME)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
