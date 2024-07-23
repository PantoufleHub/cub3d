#include "../../inc/cub3D.h"

t_calc_info init_sideDist(t_calc_info calc_info, t_vector pos)
{
	if(calc_info.rayDirX < 0)
	{
		calc_info.stepX = -1;
		calc_info.sideDistX  = (pos.x - calc_info.mapX) * calc_info.deltaDistX;
	}
	else
	{
		calc_info.stepX = 1;
		calc_info.sideDistX = (calc_info.mapX + 1.0 - pos.x) * calc_info.deltaDistX;
	}
	if(calc_info.rayDirY < 0)
	{
		calc_info.stepY = -1;
		calc_info.sideDistY = (pos.y - calc_info.mapY) * calc_info.deltaDistY;
	}
	else
	{
		calc_info.stepY = 1;
		calc_info.sideDistY = (calc_info.mapY + 1.0 - pos.y) * calc_info.deltaDistY;
	}
	return (calc_info);
}

t_calc_info get_calc_info(int x, t_vector dir, t_vector plane, t_vector pos)
{
	t_calc_info	res;
	double		cameraX;
	
	cameraX = 2 * x /(double) WIDTH - 1;
	res.rayDirX = dir.x + plane.x * cameraX;
	res.rayDirY = dir.y + plane.y * cameraX;
	res.mapX = pos.x;
	res.mapY = pos.y;
	res.deltaDistX = sqrt(1 + (res.rayDirY * res.rayDirY) / ( res.rayDirX * res.rayDirX));
	res.deltaDistY = sqrt(1 + (res.rayDirX * res.rayDirX) / (res.rayDirY * res.rayDirY));
	res = init_sideDist(res, pos);
	return (res);
}
