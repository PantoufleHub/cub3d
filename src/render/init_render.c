#include "../../inc/cub3D.h"

t_calc_info	init_side_dist(t_calc_info calc_info, t_vector pos)
{
	if (calc_info.rayDirX < 0)
	{
		calc_info.stepX = -1;
		calc_info.sideDistX = (pos.x - calc_info.mapX)
			* calc_info.deltaDistX;
	}
	else
	{
		calc_info.stepX = 1;
		calc_info.sideDistX = (calc_info.mapX + 1.0 - pos.x)
			* calc_info.deltaDistX;
	}
	if (calc_info.rayDirY < 0)
	{
		calc_info.stepY = -1;
		calc_info.sideDistY = (pos.y - calc_info.mapY) * calc_info.deltaDistY;
	}
	else
	{
		calc_info.stepY = 1;
		calc_info.sideDistY = (calc_info.mapY + 1.0 - pos.y)
			* calc_info.deltaDistY;
	}
	return (calc_info);
}

t_calc_info	get_calc_info(int x, t_vector dir, t_vector plane, t_vector pos)
{
	t_calc_info	res;
	double		camera_x;

	camera_x = 2 * x / (double) WIDTH - 1;
	res.rayDirX = dir.x + plane.x * camera_x;
	res.rayDirY = dir.y + plane.y * camera_x;
	res.mapX = (int)pos.x;
	res.mapY = (int)pos.y;
	if (res.rayDirX == 0)
		res.deltaDistX = 1e30;
	else
		res.deltaDistX = fabs(1 / res.rayDirX);
	if (res.rayDirY == 0)
		res.deltaDistY = 1e30;
	else
		res.deltaDistY = fabs(1 / res.rayDirY);
	res = init_side_dist(res, pos);
	return (res);
}
