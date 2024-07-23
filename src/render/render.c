#include "../../inc/cub3D.h"

void	render(t_data *data)
{
	int side;
	double wall_dist;
	t_line line;
	int color;
	
	data->x = 0;
	clear_screen(data);
	while(data->x < WIDTH)
	{
		data->calc_info = get_calc_info(data->x, data->vec.dir, data->vec.plane, data->vec.pos);
		side = dda(&data->calc_info, data);
		wall_dist = get_wall_dist(side, data->calc_info);
		line = get_line_height(wall_dist);
		color = create_trgb(0, 255, 0, 0);
		if(side == 1)
			color = color / 2;
		pixel_put_line(data->img, data->x, line,color);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
}
