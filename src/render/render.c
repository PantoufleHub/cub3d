#include "../../inc/cub3D.h"

void render_column(t_line wall, int side,t_data *data)
{
	int color_west;
	int color_north;
	// int color_north;
	int color;
	t_line ceiling;
	t_line floor;

	color_west = create_trgb(0, 255, 0, 0);
	color_north =  create_trgb(0, 255, 255, 255);
	// color_north = create_trgb(0, 255, 0, 0);
	color = 0;
	if(side == 1)
	{
		if (data->calc_info.stepY == -1) 
			color = color_west; // West
		if (data->calc_info.stepY == 1)
			color = color_west / 2; // East
	}
	else if (side == 0)
	{
		if (data->calc_info.stepX == -1)
			color = color_north;
		if (data->calc_info.stepX == 1)
			color = color_north / 2;
	}
	ceiling.drawStart = 0;
	ceiling.drawEnd = wall.drawStart;
	floor.drawStart = wall.drawEnd;
	floor.drawEnd = HEIGHT;
	pixel_put_line(data->img, data->x, ceiling, create_trgb(0, 0, 255, 0));
	pixel_put_line(data->img, data->x, wall,color);
	pixel_put_line(data->img, data->x, floor, create_trgb(0, 0, 0, 255));
}
void	render(t_data *data)
{
	int side;
	double wall_dist;
	t_line wall;
	
	data->x = 0;
	while(data->x < WIDTH)
	{
		data->calc_info = get_calc_info(data->x, data->vec.dir, data->vec.plane, data->vec.pos);
		side = dda(&data->calc_info, data);
		wall_dist = get_wall_dist(side, data->calc_info);
		wall = get_line_height(wall_dist);
		render_column(wall, side, data);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
}
