#include <../Headers/canvas.h>
#include <../Headers/program_init.h>

t_data *canvas_data()
{
	static t_data _canvas_data;
	return(&_canvas_data);
}

void my_pixel_put(int x, int y, int color)
{
	canvas_data()->offset = (y * canvas_data()->line_length + x * (canvas_data()->bits_per_pixel / 8));
	canvas_data()->dst = canvas_data()->addr + (canvas_data()->offset);
	*(unsigned int *)canvas_data()->dst = color;
}