#include <../Headers/keys.h>
#include <../Headers/event.h>
#include "../Headers/world.h"
#include "../Headers/libft_headers/ft_printf.h"
#include "../Headers/map_parsing.h"

t_keys *keycodes()
{
	static t_keys _keycodes;
	return (&_keycodes);
}

int key_press(int keycode)
{

	ft_printf("pressed: %i\n", keycodes()->keys[keycode]);
	if (keycode)
		keycodes()->keys[keycode] = keycode;
	keycodes()->trigger++;
	define_pos(keycode);
	
	return (0);
}

int key_release(int keycode)
{
	ft_printf("released: %i\n", keycodes()->keys[keycode]);
	if (keycode)
		keycodes()->keys[keycode] = keycode;
	keycodes()->trigger--;
	return (0);
}