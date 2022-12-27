#ifndef EVENT_H
# define EVENT_H

#include "../mlx/mlx.h"
#include "./libft_headers/ft_printf.h"
#include "./libft_headers/get_next_line.h"

void define_pos(int keycode);

typedef struct s_move
{
	int pos_y;
	int pos_x;
	int key;

}t_move;

t_move *position();
void move();

#endif