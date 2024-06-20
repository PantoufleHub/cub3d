#include "../../inc/cub3D.h"
#include <math.h>

typedef struct s_img_data
{
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
}		t_img_data;

typedef struct	s_vector
{
	double x;
	double y;

}		t_vector;

typedef struct	s_line
{
	int	drawStart;
	int	drawEnd;
}		t_line;

// void draw_square(void *mlx, void *mlx_win)
// {
// 	int x;
// 	int	y;
//
// // 	mlx_pixel_put(mlx, mlx_win, 10, 10, 0x00FF0000);
// // }
// TODO: faire une conversion map en string et int
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

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	pixel_put_line(t_img_data *data, int x,t_line line,int color)
// {
// 	while(line.drawStart != line.drawEnd)
// 		mlx_pixel_put(mlx,mlx_win,line.drawStart++, color);
// }
//
int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	void *mlx;
	int		x = 0;
	int		w = 640;
	int		h = 480;
	t_line vertical_line;
	void *mlx_win;
	t_img_data img;
	// char **map;

	t_vector plane;
	t_vector pos;
	t_vector dir;
	pos.x =  7; // x start position 
	pos.y =  3; // y start position
	dir.x =  -1; // initial direction vector
	dir.y =   0; // initial direction vector
	plane.x = 0; //the 2d raycaster version of camera plane
	plane.y = 0.66;
	// map = get_map(argv[1]);

	// verLine(x, drawStart, drawEnd, color);

	// int map[5][6] = 
	// {
	// 		{1,1,1,1,1,1},
	// 		{1,0,0,1,0,1},
	// 		{1,0,1,0,0,1},
	// 		{1,1,0,0,0,1},			
	// 		{1,1,1,1,1,1}
	// };
	// de base la vision du personnage va dans le sens de la fleche <----
	int map[25][25]=
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
	mlx_win = mlx_new_window(mlx, 640, 480 , "SALUT ALEXIS");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr (img.img, &img.bit_per_pixel, &img.size_line, &img.endian);
	while(x < 640)
	{
		double	cameraX = 2 * x /(double)w - 1;
		double rayDirX = dir.x + plane.x * cameraX;
		double rayDirY = dir.y + plane.y * cameraX;

		int mapX = (int)pos.x;
		int mapY = (int)pos.y;

		double sideDistX;
		double sideDistY;

		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
	if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - pos.x) * deltaDistX;
		}
	if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - pos.y) * deltaDistY;
		}
		//perform DDA
	while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(map[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
			else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2; if(drawEnd >= h) drawEnd = h - 1;
		vertical_line.drawStart = drawStart;
		vertical_line.drawEnd	= drawEnd;

		//choose wall color
		int color = 0x00000000;

		if(map[mapX][mapY] == 1)
		color = 0x00FF0000;
		//give x and y sides different brightness
		if(side == 1) {color = color / 2;}

		// pixel_put_line(&img, x, vertical_line, color);
		while(vertical_line.drawStart != vertical_line.drawEnd)
			// mlx_pixel_put(mlx,mlx_win,x,vertical_line.drawStart++, color);
			my_mlx_pixel_put(&img,x,vertical_line.drawStart++, color);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		x++;
	}
	mlx_loop(mlx);
	printf("%p",mlx_win);
	// printf("%s",*map);
	return (0);
}

	// double radian;
	// double res;
	// double fov;

	// radian = (90 * M_PI) / 180;
	// fov = M_PI / 3;
	// res = cos(radian);

