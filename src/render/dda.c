#include "../../inc/cub3D.h"

int dda(t_calc_info *calc_info, t_data *data)
{
	int hit;
	int side;
	
	hit = 0;
	side = 0;
	while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(calc_info->sideDistX < calc_info->sideDistY)
			{
				calc_info->sideDistX += calc_info->deltaDistX;
				calc_info->mapX += calc_info->stepX;
				side = 0;
			}
			else
			{
				calc_info->sideDistY += calc_info->deltaDistY;
				calc_info->mapY += calc_info->stepY;
				side = 1;
			}
			if(data->map[calc_info->mapX][calc_info->mapY] == '1')
				hit = 1;
		}
	return (side);
}
