#include <../Headers/map_parsing.h>
#include <../Headers/program_init.h>


//Missing the map treatment, to check if it's valid

t_map_parsing *map()
{
	static t_map_parsing _map;
	return (&_map);
}

static void read_map(int fd, int index)
{
	char *tmp;

	tmp = get_next_line(fd);
	map()->height++;
	if (tmp)
		read_map(fd, index + 1);
	else
		map()->map = malloc(sizeof(char **) * map()->height);
	if (map()->map)
		map()->map[index] = tmp;
}

void open_map()
{
	int fd;
	fd = open("./maps/map.ber", O_RDONLY);
	read_map(fd, 0);
	//int i = -1;
	//while (map()->map[++i])
		//ft_printf("%s\n", map()->map[i]);
	close(fd);
}

void map_parsing(int argc, char *argv)
{
	open_map(argc, argv);
	return;
}