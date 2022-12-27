#ifndef CANVAS_H
# define CANVAS_H

#include "../mlx/mlx.h"
#include "./libft_headers/ft_printf.h"
#include "./libft_headers/get_next_line.h"

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offset;
	char 	*dst;
} t_data;

void my_pixel_put(int x, int y, int color);
t_data *canvas_data();

#endif