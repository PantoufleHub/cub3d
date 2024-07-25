#include "../../inc/cub3D.h"

void	render(t_data *data)
{
	double	rayAngle;
	char	wall;
	double	distance;
	// double	wallHeight;
	int		color;
	t_line	line;
	t_line	ceiling;
	t_line	floor;

	rayAngle = data->player.angle - data->player.halfFov;
	data->x = 0;
	clear_screen(data);
	// int x = 0;
	// while (x < data->screen.width)
	// {
	// 	int y = 0;
	// 	while (y < data->screen.halfHeight)
	// 	{
	// 		my_mlx_pixel_put(&data->img, x, y, create_trgb(0, 0, 255, 0));
	// 		y++;
	// 	}
	// 	x++;
	// }
	while(data->x < WIDTH)
	{
		data->ray.x = data->player.x;
		data->ray.y = data->player.y;

		data->ray.rayCos = cos(degreetoRadiant(rayAngle)) / data->raycast.presicion;
		data->ray.raySin = sin(degreetoRadiant(rayAngle)) / data->raycast.presicion;
	
		// Wall finder and get the size of the ray
		wall = '0';
		while(wall == '0')
		{
			data->ray.x += data->ray.rayCos;
			data->ray.y += data->ray.raySin;
			wall = data->map[(int)data->ray.y][(int)data->ray.x];
		}
		// Pythagore gang gang.
		distance = sqrt(pow(data->player.x - data->ray.x, 2) + pow(data->player.y - data->ray.y, 2));

		// Fisheye correction.
		distance = distance * cos(degreetoRadiant(rayAngle - data->player.angle));

		// wallHeight = (data->screen.halfHeight / distance);
		line = get_line_height(distance);
		ceiling.drawStart = 0;
		ceiling.drawEnd = line.drawStart;
		floor.drawStart = line.drawEnd;
		floor.drawEnd   = HEIGHT;
		color = create_trgb(0, 255, 0, 0);

		pixel_put_line(data->img, data->x, ceiling, create_trgb(0, 255, 255, 255));
		pixel_put_line(data->img, data->x, line, color);
		pixel_put_line(data->img, data->x, floor, create_trgb(0, 0, 255, 0));

		//increment
		rayAngle += data->raycast.incrAngle;
		data->x += 1;
	}
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
}
