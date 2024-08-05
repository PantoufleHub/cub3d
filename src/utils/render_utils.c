#include "../../inc/cub3D.h"

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
// mlx_pixel_put(mlx,mlx_win,x,vertical_line.drawStart++, color);
