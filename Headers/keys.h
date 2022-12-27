#ifndef KEYS_H
# define KEYS_H

#include <stdio.h>
#include "./libft_headers/ft_printf.h"
#include "./libft_headers/get_next_line.h"
#ifdef __APPLE__
	#define ESC 53
	#define A 0
	#define S 1
	#define D 2
	#define W  13
#else
	#define ESC 65307
	#define A 97
	#define S 115
	#define D 100
	#define W  119
#endif
typedef struct s_keys
{
	int keys[70000];
	int trigger;
}t_keys;

t_keys *keycodes();
int key_press(int keycode);
int key_release(int keycode);


#endif