#include "../../inc/cub3D.h"

int w_is_in_bound(t_data *data, double movespeed)
{
	int forward;

	forward  = (int)(data->vec.pos.y + data->vec.dir.y * movespeed);

	if(data->nb_rows < forward) 
		return (FALSE);
	else
		return (TRUE);
}

int s_is_in_bound(t_data *data, double movespeed)
{
	int backward;

	backward = (int)(data->vec.pos.y - data->vec.dir.y * movespeed);

	if(data->nb_rows < backward)
		return (FALSE);
	else
		return (TRUE);
}

