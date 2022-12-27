#ifndef OBJECT_H
# define OBJECT_H

#include "../mlx/mlx.h"
#include "./libft_headers/ft_printf.h"
#include "./libft_headers/get_next_line.h"

#define CHAR_UP 0
#define CHAR_DOWN 1
#define CHAR_LEFT 2
#define CHAR_RIGHT 3
#define WALLPAPER 4
#define COIN 5
#define BLOCK 6
#define STAIR 7
#define HEART 8

typedef struct s_object
{
	void **object;
	int width;
	int height;

}t_object;

t_object *object();
void xpm_to_image();
void create_objects();

#endif
