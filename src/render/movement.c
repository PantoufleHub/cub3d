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

int	ft_keypress(int key, t_data *data)
{
	double	move_speed;
	double	rot_speed;

	move_speed = data->time.frame_time * 8.0;
	rot_speed = data->time.frame_time * 2.0;
	if (key == K_W)
	{
		if (w_is_in_bound(data, move_speed))
			forward(data, move_speed);
	}
	if (key == K_S)
	{
		if (s_is_in_bound(data, move_speed))
			backward(data, move_speed);
	}
	if (key == K_D)
		rotations(data, rot_speed);
	if (key == K_A)
		rotations(data, -rot_speed);
	if (key == K_ESC)
		on_destroy();
	return (0);
}

int	on_destroy(void)
{
	printf(RED"Game closed"WHT"\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, render, data);
	mlx_hook(data->win, E_KEYPRESS, 1L << 0, ft_keypress, data);
	return (0);
}
