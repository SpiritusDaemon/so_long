#include <../Headers/event.h>
#include <../Headers/keys.h>
#include <../Headers/program_init.h>
#include <../Headers/object.h>
#include "../Headers/map_parsing.h"
#include "../Headers/libft_headers/ft_printf.h"

static void end_program()
{
	mlx_clear_window(program()->mlx, program()->win);
	mlx_destroy_window(program()->mlx, program()->win);
	exit(0);
}

t_move *position()
{
	static t_move _position;
	return (&_position);
}

void define_pos(int keycode)
{	
	if (keycode == W)
		if (map()->map[position()->pos_y - 1][position()->pos_x] != '1')	
			position()->pos_y -= 1;
	if (keycode == S)
		if (map()->map[position()->pos_y + 1][position()->pos_x] != '1')
			position()->pos_y += 1;
	if (keycode == A)
		if (map()->map[position()->pos_y][position()->pos_x - 1] != '1')
			position()->pos_x -= 1;	
	if (keycode == D)	
		if (map()->map[position()->pos_y][position()->pos_x + 1] != '1')
			position()->pos_x += 1;	
	position()->key = keycode;
	move();
	return;
}

void move()
{
	if (position()->key == W)
		mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_UP], position()->pos_x * 32, position()->pos_y * 32);
	if (position()->key == S)
		mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_DOWN], position()->pos_x * 32, position()->pos_y * 32);
	if (position()->key == A)
		mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_LEFT], position()->pos_x * 32, position()->pos_y * 32);
	if (position()->key == D)
		mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_RIGHT], position()->pos_x * 32, position()->pos_y * 32);
	if (position()->key == ESC)
			end_program();
}

