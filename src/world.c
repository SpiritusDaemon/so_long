#include <../Headers/world.h>
#include <../Headers/map_parsing.h>
#include <../Headers/object.h>
#include <../Headers/canvas.h>
#include <../Headers/program_init.h>

void generate_world()
{
	int y;
	int x;

	y = -1;
	x = -1;
	while((++y) * 32 != program()->height)
	{
		while(map()->map[y][++x])
		{
				if(map()->map[y][x] == '1')
					mlx_put_image_to_window(program()->mlx, program()->win, object()->object[BLOCK], x * 32, y * 32);
				if(map()->map[y][x] == '0')
					mlx_put_image_to_window(program()->mlx, program()->win,object()->object[WALLPAPER], x * 32, y * 32);		
				if(map()->map[y][x] == 'C')
					mlx_put_image_to_window(program()->mlx, program()->win,object()->object[COIN], x * 32, y * 32);		

		}
		x = -1;
	}
}