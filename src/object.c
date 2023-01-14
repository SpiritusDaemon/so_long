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
	object()->object[HEART] = mlx_xpm_file_to_image(program()->mlx ,"./xpm_files/heart.xpm", &object()->width, &object()->height);
}
void create_objects()
{
	xpm_to_image();
}