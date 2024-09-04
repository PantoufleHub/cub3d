#include "../../inc/cub3D.h"

void	render_column(t_line wall, int side, t_data *data)
{
	t_line	ceiling;
	t_line	floor;
	int		color;
	int test = 0;

	color = 0;
	color = wallside(data, side);
	ceiling.drawStart = 0;
	ceiling.drawEnd = wall.drawStart;
	floor.drawStart = wall.drawEnd;
	floor.drawEnd = HEIGHT;

	// printf("Start: %d | End: %d\n", wall.drawStart, wall.drawEnd);
	pixel_put_line(data->img, data->x, ceiling, data->ceiling_color);
	// pixel_put_line(data->img, data->x, wall, color);
	test = wall.drawStart;
	int c;
	// printf("Walldist : [%f]\n", data->calc_info.perpWallDist);
	int wall_w = WIDTH / data->calc_info.perpWallDist;
	int wall_h = HEIGHT / data->calc_info.perpWallDist;
	int	step_x = wall_w / data->textures[0].width;
	int	step_y = wall_h / data->textures[0].height;
	if(step_y == 0)
		step_y = 1;
	// int c = create_trgb(0, 255, 0, 0);
	// printf("Wall pos  [ %f , %f ]\n", data->calc_info.wall_pos.x, data->calc_info.wall_pos.y);
	// printf("Wall size [ %d , %d ]\n", wall_w, wall_h);
	while (test < wall.drawEnd)
	{
		// printf("CLACULDUCUL: %d, %d, %d, %d\n", test, wall.drawStart, wall.drawEnd, wall.drawEnd-wall.drawStart/4);
		int n = ((test - wall.drawStart)/ step_y) * data->textures[0].width
			+ (int)((fmod(data->calc_info.wall_pos.x, 1.0) * (wall_w))/step_x);
		// int n = fmod(data->calc_info.wall_pos.x, 1.0) * (double)data->textures[0].width;
		if (n < 0)
			printf("ti souci\n"), n = 0;
		if (n > data->textures[0].width * data->textures[0].height)
			printf("gro souci\n"), n = data->textures[0].width * data->textures[0].height;
		c = ((int *)(data->textures[0].img_data->addr))[n];
		// printf("Color: %d\n", c);
		// mlx_pixel_put(data->mlx, data->win, data->x, test, c);
		my_mlx_pixel_put(&data->img, data->x, test, c);
		test++;
	}
	pixel_put_line(data->img, data->x, floor, data->floor_color);
}

int	render(t_data *data)
{
	int		side;
	t_line	wall;

	data->x = 0;
	data->time.oldTime = data->time.time;
	data->time.time = get_time_elapse(data->time.ref_time) / 1000.0;
	data->time.FrameTime = (data->time.time - data->time.oldTime);
	while (data->x < WIDTH)
	{
		data->calc_info = get_calc_info(data->x, data->vec.dir, data->vec.plane,
				data->vec.pos);
		side = dda(&data->calc_info, data);
		data->calc_info.perpWallDist = get_wall_dist(side, data->calc_info);
		wall = get_line_height(data->calc_info.perpWallDist);
		render_column(wall, side, data);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
