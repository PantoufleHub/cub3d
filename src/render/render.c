#include "../../inc/cub3D.h"

void render_column(t_line wall, int side,t_data *data)
{
	t_line ceiling;
	t_line floor;
	int color;

	color = 0;
	color = wallside(data,side);
	ceiling.drawStart = 0;
	ceiling.drawEnd = wall.drawStart;
	floor.drawStart = wall.drawEnd;
	floor.drawEnd = HEIGHT;
	pixel_put_line(data->img, data->x, ceiling, create_trgb(0, 0, 255, 0));
	pixel_put_line(data->img, data->x, wall,color);
	pixel_put_line(data->img, data->x, floor, create_trgb(0, 0, 0, 255));
}
int	render(t_data *data)
{
	int side;
	double wall_dist;
	t_line wall;
	
	data->x = 0;
	data->time.oldTime = data->time.time;
	data->time.time = get_time_elapse(data->time.ref_time) / 1000.0;
	data->time.FrameTime = (data->time.time - data->time.oldTime); 
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
	return (0);
}
