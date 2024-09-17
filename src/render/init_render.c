/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:08:08 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/17 11:08:09 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_calc_info	init_side_dist(t_calc_info calc_info, t_vector pos)
{
	if (calc_info.ray_dir_x < 0)
	{
		calc_info.step_x = -1;
		calc_info.s_dist_x = (pos.x - calc_info.map_x)
			* calc_info.d_dist_x;
	}
	else
	{
		calc_info.step_x = 1;
		calc_info.s_dist_x = (calc_info.map_x + 1.0 - pos.x)
			* calc_info.d_dist_x;
	}
	if (calc_info.ray_dir_y < 0)
	{
		calc_info.step_y = -1;
		calc_info.s_dist_y = (pos.y - calc_info.map_y) * calc_info.d_dist_y;
	}
	else
	{
		calc_info.step_y = 1;
		calc_info.s_dist_y = (calc_info.map_y + 1.0 - pos.y)
			* calc_info.d_dist_y;
	}
	return (calc_info);
}

t_calc_info	get_calc_info(int x, t_vector dir, t_vector plane, t_vector pos)
{
	t_calc_info	res;
	double		camera_x;

	camera_x = 2 * x / (double) WIDTH - 1;
	res.ray_dir_x = dir.x + plane.x * camera_x;
	res.ray_dir_y = dir.y + plane.y * camera_x;
	res.map_x = (int)pos.x;
	res.map_y = (int)pos.y;
	if (res.ray_dir_x == 0)
		res.d_dist_x = 1e30;
	else
		res.d_dist_x = fabs(1 / res.ray_dir_x);
	if (res.ray_dir_y == 0)
		res.d_dist_y = 1e30;
	else
		res.d_dist_y = fabs(1 / res.ray_dir_y);
	res = init_side_dist(res, pos);
	return (res);
}
