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
		if (calc_info->s_dist_x < calc_info->s_dist_y)
		{
			calc_info->s_dist_x += calc_info->d_dist_x;
			calc_info->map_x += calc_info->step_x;
			side = 0;
		}
		else
		{
			calc_info->s_dist_y += calc_info->d_dist_y;
			calc_info->map_y += calc_info->step_y;
			side = 1;
		}
		if (data->map[calc_info->map_y][calc_info->map_x] == '1')
			hit = 1;
	}
	return (side);
}
