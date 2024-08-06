#include "../../inc/cub3D.h"

//TODO: Free la memoire des anciennes images pour eviter la surcharge de memoire.
char **get_map(char *path)
{
	int		map_fd;
	char	**map;
	char	*line;
	int		x;

	x = 0;
	map = ft_calloc(6, sizeof(int *)); // TODO: The Height of the map need to be calculated automaticelly
	map_fd = open(path, O_RDONLY);
	if (map_fd < 0)
	{
		perror("CUB3D: ");
		return (NULL);
	}
	line = get_next_line(map_fd);
	while(line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		map[x++] = line;
		line = get_next_line(map_fd);
	}
	return (map);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	t_data data;
	char **map;

	data.x = 0;
	
	data.raycast.presicion = 64;
	
	data.player.fov = 60;
	data.player.x = 3;
	data.player.y = 3;
	data.player.angle = NORTH;

	// calculate the value
	data.screen.halfWidth = WIDTH / 2.0;
	data.screen.halfHeight = HEIGHT / 2.0;
	data.raycast.incrAngle = data.player.fov / WIDTH;
	data.player.halfFov = data.player.fov / 2;
	
	map = get_map(argv[1]);
	data.map = map;
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "SALUT ALEXIS");
	data.img.img = mlx_new_image(data.mlx.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr (data.img.img, &data.img.bit_per_pixel, &data.img.size_line, &data.img.endian);
	ft_controls(&data);
	refresh(&data);
	data.x = 0;
	mlx_loop(data.mlx.mlx);
}
