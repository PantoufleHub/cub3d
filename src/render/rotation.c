/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:08:51 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/17 11:08:52 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	rotations(t_data *data, double rotspeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->vec.dir.x;
	data->vec.dir.x = data->vec.dir.x * cos(rotspeed)
		- data->vec.dir.y * sin(rotspeed);
	data->vec.dir.y = old_dir_x * sin(rotspeed)
		+ data->vec.dir.y * cos(rotspeed);
	old_plane_x = data->vec.plane.x;
	data->vec.plane.x = data->vec.plane.x
		* cos(rotspeed) - data->vec.plane.y * sin(rotspeed);
	data->vec.plane.y = old_plane_x
		* sin(rotspeed) + data->vec.plane.y * cos(rotspeed);
}
