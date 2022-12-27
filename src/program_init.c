#include "../Headers/program_init.h"
#include <../Headers/keys.h>
#include <../Headers/object.h>
#include <../Headers/canvas.h>
#include <../Headers/map_parsing.h>
#include <../Headers/world.h>

t_program_init *program()
{
	static t_program_init _program;
	return (&_program);
}

void program_init()
{
	int x;
	int y;
	y = -1;
	x = -1;
	program()->width = 0;
	program()->height = 0;
	while(map()->map[++y])
	{
		x = -1;
		while(map()->map[y][++x])
			;
	}
	program()->height = y * 32;
	program()->width = x * 32;
	ft_printf("valor de width:%i + valor de height:%i\n", program()->width, program()->height);

	program()->mlx = mlx_init();
	program()->win = mlx_new_window(program()->mlx, program()->width,program()->height, "so_long");
}

int	update(void)
{
	static int	i;

	printf("O valor do i %i\n", i++);
	return i;
}

int main()
{
	map_parsing(2, "./maps/map.ber");
	program_init();
	create_objects();
	generate_world();
	mlx_hook(program()->win, 2, (1L<<0), key_press, NULL);
	mlx_hook(program()->win, 3, (1L<<1), key_release, NULL);
	//mlx_loop_hook(program()->mlx, update, NULL);
	mlx_loop(program()->mlx);
	return (0);
}