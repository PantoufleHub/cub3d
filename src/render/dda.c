/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:06:40 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/17 11:07:42 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	dda(t_calc_info *calc_info, t_data *data)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
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
		if (data->map[calc_info->mapY][calc_info->mapX] == '1')
			hit = 1;
	}
	return (side);
}
