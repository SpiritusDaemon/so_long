#include <../Headers/object.h>
#include <../Headers/program_init.h>
#include <../Headers/canvas.h>

t_object *object()
{ 
	static t_object _objects;
	return (&_objects); 
}

void xpm_to_image()
{
	object()->object = malloc(sizeof(char *) * 8);
	object()->object[CHAR_UP] = mlx_xpm_file_to_image(program()->mlx,"./xpm_files/character_up.xpm", &object()->width, &object()->height);
	object()->object[CHAR_DOWN] = mlx_xpm_file_to_image(program()->mlx,"./xpm_files/character_down.xpm", &object()->width, &object()->height);
	object()->object[CHAR_LEFT] = mlx_xpm_file_to_image(program()->mlx,"./xpm_files/character_left.xpm", &object()->width, &object()->height);
	object()->object[CHAR_RIGHT] = mlx_xpm_file_to_image(program()->mlx,"./xpm_files/character_right.xpm", &object()->width, &object()->height);
	object()->object[WALLPAPER] =  mlx_xpm_file_to_image(program()->mlx,"./xpm_files/wallpaper.xpm", &object()->width, &object()->height);
	object()->object[BLOCK] =  mlx_xpm_file_to_image(program()->mlx,"./xpm_files/block.xpm", &object()->width, &object()->height);
	object()->object[COIN] = mlx_xpm_file_to_image(program()->mlx ,"./xpm_files/heart.xpm", &object()->width, &object()->height);
}

/* static void create_character_up()
{
	
}

static void create_character_down()
{
	mlx_get_data_addr(object()->object[CHAR_DOWN],&canvas_data()->bits_per_pixel, &canvas_data()->line_length, &canvas_data()->endian);
}

static void create_character_left()
{
	mlx_get_data_addr(object()->object[CHAR_LEFT],&canvas_data()->bits_per_pixel, &canvas_data()->line_length, &canvas_data()->endian);
}

static void create_character_right()
{
	mlx_get_data_addr(object()->object[CHAR_RIGHT],&canvas_data()->bits_per_pixel, &canvas_data()->line_length, &canvas_data()->endian);
}
 */
void create_objects()
{
	xpm_to_image();
	/* create_character(); */
}