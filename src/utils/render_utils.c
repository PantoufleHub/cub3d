#include "../../inc/cub3D.h"

double get_wall_dist(int side, t_calc_info calc_info)
{
	double	wall_dist;

	if(side == 0) 
		wall_dist = (calc_info.sideDistX - calc_info.deltaDistX);
	else
		wall_dist = (calc_info.sideDistY - calc_info.deltaDistY);
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

void pixel_put_line(&img, x, vertical_line, color);
