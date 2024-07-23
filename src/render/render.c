#include "../../inc/cub3D.h"

// void	render(t_data *data)
// {
// 	int side;
// 	double wall_dist;
// 	t_line line;
// 	int color;
// 	
// 	data->x = 0;
// 	clear_screen(data);
// 	while(data->x < WIDTH)
// 	{
// 		data->calc_info = get_calc_info(data->x, data->vec.dir, data->vec.plane, data->vec.pos);
// 		side = dda(&data->calc_info, data);
// 		wall_dist = get_wall_dist(side, data->calc_info);
// 		line = get_line_height(wall_dist);
// 		color = create_trgb(0, 255, 0, 0);
// 		if(side == 1)
// 			color = color / 2;
// 		pixel_put_line(data->img, data->x, line, color);
// 		data->x++;
// 	}
// 	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
// }
void	render(t_data *data)
{
	double	rayAngle;
	char	wall;
	double	distance;
	// double	wallHeight;
	int		color;
	t_line	line;

	rayAngle = data->player.angle - data->player.halfFov;
	data->x = 0;
	clear_screen(data);
	while(data->x < data->screen.width)
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
			wall = data->map[(int)data->ray.x][(int)data->ray.y];
		}
		distance = sqrt(pow(data->player.x - data->ray.x,2) + pow(data->player.y - data->ray.y,2));
		// wallHeight = (data->screen.halfHeight / distance);
		line = get_line_height(distance);
		color = create_trgb(0, 255, 0, 0);
		pixel_put_line(data->img, data->x, line, color);
		//increment
		rayAngle += data->raycast.incrAngle;
		data->x++;
	}
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
}
