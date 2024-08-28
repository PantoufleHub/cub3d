#include "../../inc/cub3D.h"

int wallside(t_data *data, int side)
{
	int color_east;
	int color_north;
	int color;

	color = 0;
	color_east = create_trgb(0, 255, 0, 0);
	color_north =  create_trgb(0, 255, 255, 255);
	if(side == 1)
	{
		if (data->calc_info.stepY == -1) 
			color = color_east;
		if (data->calc_info.stepY == 1)
			color = color_east / 2; // WEST
	}
	else if (side == 0)
	{
		if (data->calc_info.stepX == -1)
			color = color_north;
		if (data->calc_info.stepX == 1)
			color = color_north / 2; // SOUTH
	}
	return (color);
}

double get_wall_dist(int side, t_calc_info calc_info)
{
	double	wall_dist;

	if(side == 0) 
		wall_dist = (calc_info.sideDistX - calc_info.deltaDistX);
	else
		wall_dist = (calc_info.sideDistY - calc_info.deltaDistY);
	if(wall_dist == 0)
		wall_dist = 1;
	return (wall_dist);
}

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
		while(vertical_line.drawStart != vertical_line.drawEnd)
			my_mlx_pixel_put(&img,x,vertical_line.drawStart++, color);
}

