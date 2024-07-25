#include "../../inc/cub3D.h"

// double get_wall_dist(int side, t_calc_info calc_info)
// {
// 	double	wall_dist;
//
// 	if(side == 0) 
// 	{
// 		wall_dist = (calc_info.sideDistX - calc_info.deltaDistX);
// 		if(wall_dist == 0)
// 			wall_dist = 0.1;
// 	}
// 	else
// 	{
// 		wall_dist = (calc_info.sideDistY - calc_info.deltaDistY);
// 		if(wall_dist == 0)
// 			wall_dist = 0.1;
// 	}
//
//
// 	return (wall_dist);
// }

t_line get_line_height(double wall_dist)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	t_line res;

	lineHeight = (int)(HEIGHT / wall_dist);
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if(drawStart < 0) 
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2; 
	if(drawEnd >= HEIGHT) 
		drawEnd = HEIGHT - 1;
	res.drawStart = drawStart;
	res.drawEnd = drawEnd;
	return (res);
}

void pixel_put_line(t_img_data img, int x, t_line vertical_line, int color)
{
		while(vertical_line.drawStart < vertical_line.drawEnd)
			my_mlx_pixel_put(&img,x,vertical_line.drawStart++, color);
}

void clear_screen(t_data *data)
{
	int x;
	t_line ver_line;
	
	ver_line.drawStart = 0;
	ver_line.drawEnd = HEIGHT;
	x = 0;
	while(x < WIDTH)
	{
		pixel_put_line(data->img, x, ver_line, 0);
		x++;
	}
}
// mlx_pixel_put(mlx,mlx_win,x,vertical_line.drawStart++, color);
