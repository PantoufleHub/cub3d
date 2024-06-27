#include "../../inc/cub3D.h"

char **get_map(char *path)
{
	int		map_fd;
	char	**map;
	char	*line;
	char	*temp_line;
	int		x;

	x = 0;
	map = ft_calloc(6, sizeof(char *)); // TODO: The Height of the map need to be calculated automaticelly
	map_fd = open(path, O_RDONLY);
	if (map_fd < 0)
	{
		perror("CUB3D: ");
		return (NULL);
	}
	line = get_next_line(map_fd);
	while(line != NULL)
	{
		temp_line = ft_calloc(ft_strlen(line), sizeof(char));
		temp_line = line;
		map[x++] = temp_line;
		line = get_next_line(map_fd);
	}
	free(temp_line);
	return (map);
}

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	void	*mlx;
	int		x = 0;
	void *mlx_win;
	t_img_data img;
	t_calc_info calc_infos;

	t_vector plane;
	t_vector pos;
	t_vector dir;
	pos.x =  22; // x start position 
	pos.y =  12; // y start position
	dir.x =  -1; // initial direction vector
	dir.y =  0; // initial direction vector
	plane.x = 0; //the 2d raycaster version of camera plane
	plane.y = 0.66;
	// int **map;
	// int map[6][7] = 
	// {
	// 		{1,1,1,1,1,1},
	// 		{1,0,0,1,0,1},
	// 		{1,0,1,0,0,1},
	// 		{1,1,0,0,0,1},
	// 		{1,1,1,1,1,1}
	// };
	// de base la vision du personnage va dans le sens de la fleche <----
	//
	int map[25][25]= // TODO: Faire une fonction d'allocation memoire pout l'utiliser en tant que int **
		{
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
			{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
			{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "SALUT ALEXIS");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr (img.img, &img.bit_per_pixel, &img.size_line, &img.endian);
	while(x < WIDTH)
	{
		int side;
		double wall_dist;
		t_line line;

		calc_infos = get_calc_info(x, dir, plane, pos);
		side = dda(&calc_infos);
		wall_dist = get_wall_dist(side, calc_infos);
		line = get_line_height(wall_dist);

		//choose wall color
		int color = 0x00000000;

		if(map[calc_infos.mapX][calc_infos.mapY] == 1)
			color = create_trgb(0, 255, 0, 0);
		if(side == 1) 
			color = color / 2;
		pixel_put_line(img, x, line,color);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		x++;

	}
		mlx_loop(mlx);
// 		// pixel_put_line(&img, x, vertical_line, color);
// 		x++;
// 	}
// 	mlx_loop(mlx);
// 	printf("%p",mlx_win);
// 	// printf("%s",*map);
// 	return (0);
// }
//
// 	// double radian;
// 	// double res;
// 	// double fov;
//
// 	// radian = (90 * M_PI) / 180;
// 	// fov = M_PI / 3;
// 	// res = cos(radian);
//
}
