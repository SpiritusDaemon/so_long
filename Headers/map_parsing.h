#ifndef MAP_PARSING_H
# define MAP_PARSING_H

typedef struct s_map_parsing
{
	char **map;
	int width;
	int height;

}t_map_parsing;

t_map_parsing *map();
void open_map(int argc, char *argv);
void map_parsing(int argc, char *argv);


#endif