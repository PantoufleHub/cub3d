#include "../../inc/cub3D.h"

int	dda(t_calc_info *calc_info, t_data *data)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (calc_info->sideDistX < calc_info->sideDistY)
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
		if(data->map[calc_info->mapY][calc_info->mapX] == '1')
		{
			// if (calc_info->sideDistX <= calc_info->sideDistY)
			// 	calc_info->wall_pos.x = calc_info->rayDirX * calc_info->sideDistX + data->vec.pos.x;
			// 	// calc_info->wall_pos.y = calc_info->rayDirY * calc_info->sideDistX + data->vec.pos.y;
			// else
			// 	calc_info->wall_pos.x = calc_info->rayDirX * calc_info->sideDistY + data->vec.pos.x;
			// 	// calc_info->wall_pos.y = calc_info->rayDirY * calc_info->sideDistY + data->vec.pos.y;
			// printf("Wall posx [%f]\n", fmod(calc_info->wall_pos.x, 1.0));
			hit = 1;
		}
	}
	return (side);
}
