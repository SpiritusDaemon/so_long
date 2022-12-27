#include <../Headers/event.h>
#include <../Headers/keys.h>
#include <../Headers/program_init.h>
#include <../Headers/object.h>

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
	switch (keycode)
	{
	case W:
		position()->pos_y -= 20;
		break;
	case S:
		position()->pos_y += 20;
		break;
	case A:
		position()->pos_x -= 20;
		break;
	case D:
		position()->pos_x += 20; 
		break;
	default:
		break;
	}
	position()->key = keycode;
	move();
}

void move()
{
	switch (position()->key)
	{
		case W:
			mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_UP], position()->pos_x, position()->pos_y);
		break;
		case S:
			mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_DOWN], position()->pos_x, position()->pos_y);
		break;
		case A:
			mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_LEFT], position()->pos_x, position()->pos_y);
		break;
		case D:
			mlx_put_image_to_window(program()->mlx, program()->win, object()->object[CHAR_RIGHT], position()->pos_x, position()->pos_y);
		break;
		case ESC:
			 end_program();
		break;
	}
}

