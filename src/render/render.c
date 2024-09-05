#include "../../inc/cub3D.h"

void	render_column(t_line wall, t_data *data)
{
	t_line	ceiling;
	t_line	floor;
	int 	color;

	ceiling.drawStart = 0;
	ceiling.drawEnd = wall.drawStart;
	floor.drawStart = wall.drawEnd;
	floor.drawEnd = HEIGHT;
	pixel_put_line(data->img, data->x, ceiling, data->ceiling_color);	
	int line_height = HEIGHT / data->calc_info.perpWallDist;
	if (line_height == 0)
		line_height = 1;
	double step = 1.0 * (double)data->textures[data->calc_info.wall_side].height / (double)line_height;
    double texPos = (double)((double)wall.drawStart - HEIGHT / 2 + (double)line_height / 2) * step;
      for(int y = wall.drawStart; y < wall.drawEnd; y++)
      {
        int texY = (int)texPos;
        texPos += step;
        color = ((int *)(data->textures[data->calc_info.wall_side].img_data->addr))[data->textures[data->calc_info.wall_side].width * texY + data->calc_info.tex_x];
		my_mlx_pixel_put(&data->img, data->x, y, color);
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
		if (side == 0)
			data->calc_info.wall_x = data->vec.pos.y + data->calc_info.perpWallDist * data->calc_info.rayDirY;
      	else
			data->calc_info.wall_x = data->vec.pos.x + data->calc_info.perpWallDist * data->calc_info.rayDirX;
		data->calc_info.wall_x = (fmod(data->calc_info.wall_x, 1.0));
		set_wallside(data, side);
		data->calc_info.tex_x = (int)(data->calc_info.wall_x * (double)(data->textures[data->calc_info.wall_side].width));
    	if(side == 0 && data->calc_info.rayDirX > 0)
			data->calc_info.tex_x = data->textures[data->calc_info.wall_side].width - data->calc_info.tex_x - 1;
      	if(side == 1 && data->calc_info.rayDirY < 0)
			data->calc_info.tex_x = data->textures[data->calc_info.wall_side].width - data->calc_info.tex_x - 1;
		render_column(wall, data);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
