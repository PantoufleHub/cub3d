/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:08:30 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/18 14:17:57 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	forward(t_data *data, double move_speed)
{
	if (data->map[(int)(data->vec.pos.y + data->vec.dir.y * move_speed)]
		[(int)(data->vec.pos.x)] == '0')
		data->vec.pos.y += data->vec.dir.y * move_speed;
	if (data->map[(int)(data->vec.pos.y)]
		[(int)(data->vec.pos.x + data->vec.dir.x * move_speed)] == '0')
		data->vec.pos.x += data->vec.dir.x * move_speed;
}

void	backward(t_data *data, double move_speed)
{
	if (data->map[(int)(data->vec.pos.y - data->vec.dir.y * move_speed)]
		[(int)(data->vec.pos.x)] == '0')
		data->vec.pos.y -= data->vec.dir.y * move_speed;
	if (data->map[(int)(data->vec.pos.y)]
		[(int)(data->vec.pos.x - data->vec.dir.x * move_speed)] == '0')
		data->vec.pos.x -= data->vec.dir.x * move_speed;
}
