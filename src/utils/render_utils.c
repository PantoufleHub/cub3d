#include "../../inc/cub3D.h"

void	set_wallside(t_data *data, int side)
{
	if (side == 1)
	{
		if (data->calc_info.step_y == -1)
			data->calc_info.wall_side = 0;
		if (data->calc_info.step_y == 1)
			data->calc_info.wall_side = 2;
	}
	else if (side == 0)
	{
		if (data->calc_info.step_x == -1)
			data->calc_info.wall_side = 3;
		if (data->calc_info.step_x == 1)
			data->calc_info.wall_side = 1;
	}
}

double	get_wall_dist(int side, t_calc_info calc_info)
{
	double	wall_dist;

	if (side == 0)
		wall_dist = (calc_info.s_dist_x - calc_info.d_dist_x);
	else
		wall_dist = (calc_info.s_dist_y - calc_info.d_dist_y);
	if (wall_dist == 0)
		wall_dist = 0.1;
	return (wall_dist);
}

t_line	get_line_height(double wall_dist)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_line	res;

	line_height = (int)(HEIGHT / wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	res.draw_start = draw_start;
	res.draw_end = draw_end;
	return (res);
}

void	pixel_put_line(t_img_data img, int x, t_line vertical_line, int color)
{
	while (vertical_line.draw_start != vertical_line.draw_end)
		my_mlx_pixel_put(&img, x, vertical_line.draw_start++, color);
}
