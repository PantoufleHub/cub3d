#include "../../inc/cub3D.h"

void	render_column(t_line wall, t_data *data)
{
	t_line	ceil_flo[2];
	double	s_tpos[2];
	int		y_texy[2];

	ceil_flo[0].draw_start = 0;
	ceil_flo[0].draw_end = wall.draw_start;
	ceil_flo[1].draw_start = wall.draw_end;
	ceil_flo[1].draw_end = HEIGHT;
	pixel_put_line(data->img, data->x, ceil_flo[0], data->ceiling_color);
	s_tpos[0] = 1.0 * data->textures[data->calc_info.wall_side].height
		/ (double)(HEIGHT / data->calc_info.perp_dist);
	s_tpos[1] = (double)((double)wall.draw_start - HEIGHT
			/ 2 + (double)(HEIGHT / data->calc_info.perp_dist) / 2) *s_tpos[0];
	y_texy[0] = wall.draw_start - 1;
	while (++y_texy[0] < wall.draw_end)
	{
		y_texy[1] = (int)s_tpos[1];
		s_tpos[1] += s_tpos[0];
		my_mlx_pixel_put(&data->img, data->x, y_texy[0],
			((int *)(data->textures[data->calc_info.wall_side].img_data->addr))
		[data->textures[data->calc_info.wall_side].width * y_texy[1]
			+ ((data->textures[data->calc_info.wall_side].width
					- data->calc_info.tex_x) - 1)]);
	}
	pixel_put_line(data->img, data->x, ceil_flo[1], data->floor_color);
}

void	please_the_norminette(t_data *data, int *side, t_line *wall)
{
	*side = dda(&data->calc_info, data);
	data->calc_info.perp_dist = get_wall_dist(*side, data->calc_info);
	*wall = get_line_height(data->calc_info.perp_dist);
	if (*side == 0)
		data->calc_info.wall_x = data->vec.pos.y
			+ data->calc_info.perp_dist * data->calc_info.ray_dir_y;
	else
		data->calc_info.wall_x = data->vec.pos.x
			+ data->calc_info.perp_dist * data->calc_info.ray_dir_x;
	data->calc_info.wall_x = (fmod(data->calc_info.wall_x, 1.0));
	set_wallside(data, *side);
	data->calc_info.tex_x = (int)(data->calc_info.wall_x
			* (double)(data->textures[data->calc_info.wall_side].width));
}

int	render(t_data *data)
{
	int		side;
	t_line	wall;

	data->x = 0;
	data->time.old_time = data->time.time;
	data->time.time = get_time_elapse(data->time.ref_time) / 1000.0;
	data->time.frame_time = (data->time.time - data->time.old_time);
	while (data->x < WIDTH)
	{
		data->calc_info = get_calc_info(data->x, data->vec.dir, data->vec.plane,
				data->vec.pos);
		please_the_norminette(data, &side, &wall);
		if (side == 0 && data->calc_info.ray_dir_x > 0)
			data->calc_info.tex_x = data->textures
			[data->calc_info.wall_side].width - data->calc_info.tex_x - 1;
		if (side == 1 && data->calc_info.ray_dir_y < 0)
			data->calc_info.tex_x = data->textures
			[data->calc_info.wall_side].width - data->calc_info.tex_x - 1;
		render_column(wall, data);
		data->x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
