#include "../../inc/cub3D.h"

void	render(t_data *data, double distance)
{
	t_line	wall;
	t_line	ceiling;
	t_line	floor;
	int		color;

	wall = get_line_height(distance);
	ceiling.drawStart = 0;
	ceiling.drawEnd = wall.drawStart;
	floor.drawStart = wall.drawEnd;
	floor.drawEnd = HEIGHT;
	color = create_trgb(0, 255, 0, 0);
	pixel_put_line(data->img, data->x, ceiling, create_trgb(0, 255, 255, 255));
	pixel_put_line(data->img, data->x, wall, color);
	pixel_put_line(data->img, data->x, floor, create_trgb(0, 0, 255, 0));
}

void	refresh(t_data *data)
{
	double	distance;

	data->ray.rayAngle = data->player.angle - data->player.halfFov;
	data->x = 0;
	clear_screen(data);
	while (data->x < WIDTH)
	{
		distance = raycasting(data);
		render(data, distance);
		data->ray.rayAngle += data->raycast.incrAngle;
		data->x += 1;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->img.img, 0, 0);
}
