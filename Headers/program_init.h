#ifndef PROGRAM_INIT_H
# define PROGRAM_INIT_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "./libft_headers/ft_printf.h"
#include "./libft_headers/get_next_line.h"


typedef struct s_program_init
{
	void *mlx;
	void *win;
	int width;
	int height;
	int x;
	int y;
}t_program_init;

t_program_init *program();
void program_init();


#endif