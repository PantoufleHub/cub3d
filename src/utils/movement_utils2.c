/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:53:19 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/18 15:11:59 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	d_is_in_bound(t_data *data, double move_speed)
{
	int	right_y;
	int	right_x;
	int	column_nbr;

	right_y = (int)(data->vec.pos.y + data->vec.plane.y * move_speed);
	right_x = (int)(data->vec.pos.x + data->vec.plane.x * move_speed);
	if (data->nb_rows <= right_y || right_y < 0)
		return (FALSE);
	column_nbr = ft_strlen(data->map[right_y]);
	if (column_nbr <= right_x || right_x < 0)
		return (FALSE);
	else
		return (TRUE);
}

static int	a_is_in_bound(t_data *data, double move_speed)
{
	int	left_y;
	int	left_x;
	int	column_nbr;

	left_y = (int)(data->vec.pos.y - data->vec.plane.y * move_speed);
	left_x = (int)(data->vec.pos.x - data->vec.plane.x * move_speed);
	if (data->nb_rows <= left_y || left_y < 0)
		return (FALSE);
	column_nbr = ft_strlen(data->map[left_y]);
	if (column_nbr <= left_x || left_x < 0)
		return (FALSE);
	else
		return (TRUE);
}

void	left(t_data *data, double move_speed)
{
	if (d_is_in_bound(data, move_speed))
	{
		if (data->map[(int)(data->vec.pos.y + data->vec.plane.y * move_speed)]
			[(int)data->vec.pos.x] == '0')
			data->vec.pos.y += (data->vec.plane.y) * move_speed;
		if (data->map[(int)(data->vec.pos.y)]
			[(int)(data->vec.pos.x + data->vec.plane.x * move_speed)] == '0')
			data->vec.pos.x += data->vec.plane.x * move_speed;
	}
}

void	right(t_data *data, double move_speed)
{
	if (a_is_in_bound(data, move_speed))
	{
		if (data->map[(int)(data->vec.pos.y - data->vec.plane.y * move_speed)]
			[(int)data->vec.pos.x] == '0')
			data->vec.pos.y -= (data->vec.plane.y) * move_speed;
		if (data->map[(int)(data->vec.pos.y)]
			[(int)(data->vec.pos.x - data->vec.plane.x * move_speed)] == '0')
			data->vec.pos.x -= data->vec.plane.x * move_speed;
	}
}
