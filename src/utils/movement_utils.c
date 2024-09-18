/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:16:08 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 15:40:24 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	w_is_in_bound(t_data *data, double move_speed)
{
	int	forward_y;
	int	forward_x;
	int	column_nbr;

	forward_y = (int)(data->vec.pos.y + data->vec.dir.y * move_speed);
	forward_x = (int)(data->vec.pos.x + data->vec.dir.x * move_speed);
	if (data->nb_rows < forward_y || forward_y < 0)
		return (FALSE);
	column_nbr = ft_strlen(data->map[forward_y]);
	if (column_nbr < forward_x || forward_x < 0)
		return (FALSE);
	else
		return (TRUE);
}

int	s_is_in_bound(t_data *data, double move_speed)
{
	int	backward_y;
	int	backward_x;
	int	column_nbr;

	backward_y = (int)(data->vec.pos.y - data->vec.dir.y * move_speed);
	backward_x = (int)(data->vec.pos.x - data->vec.dir.x * move_speed);
	if (data->nb_rows < backward_y || backward_y < 0)
		return (FALSE);
	column_nbr = ft_strlen(data->map[backward_y]);
	if (column_nbr < backward_x || backward_x < 0)
		return (FALSE);
	else
		return (TRUE);
}
