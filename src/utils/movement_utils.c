#include "../../inc/cub3D.h"

int	w_is_in_bound(t_data *data, double move_speed)
{
	int	forward_y;
	int	forward_x;

	forward_y = (int)(data->vec.pos.y + data->vec.dir.y * move_speed);
	forward_x = (int)(data->vec.pos.x + data->vec.dir.x * move_speed);
	if (data->nb_rows < forward_y)
		return (FALSE);
	else
		return (TRUE);
}

int	s_is_in_bound(t_data *data, double move_speed)
{
	int	backward_y;
	int	backward_x;

	backward_y = (int)(data->vec.pos.y - data->vec.dir.y * move_speed);
	backward_x = (int)(data->vec.pos.x - data->vec.dir.x * move_speed);
	if (data->nb_rows < backward_y)
		return (FALSE);
	else
		return (TRUE);
}
