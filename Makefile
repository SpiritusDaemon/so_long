NAME = so_long
FUNC = src/program_init.c \
		src/keys.c \
		src/object.c \
		src/event.c \
		src/canvas.c \
		src/map_parsing.c \
		src/world.c \
		libft/get_next_line.c \
		libft/get_next_line_utils.c \
		libft/ft_printf.c \
		libft/ft_printf_utils.c \
		libft/ft_printf_more_utils.c \


INCLUDES	= 	-IHeaders -IHeaders/libft
OBJS		= 	$(FUNC:.c=.o)

MLX_LIB_DIR = mlx
MLX_INCLUDE = -Imlx
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c $(MLX_LIB_DIR)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean: 
		rm -rf *.o

fclean: clean
		rm -rf $(NAME)
		rm -rf ./a.out
		rm -rf ./src/*.o
		rm -rf ./libft/*.o
re: fclean
	make 
	make clean

.PHONY: all fclean clean re
	