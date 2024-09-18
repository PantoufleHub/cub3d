#include "../inc/cub3D.h"

int	ft_keypress(int key, t_data *data)
{
	double	move_speed;
	double	rot_speed;

	move_speed = data->time.frame_time * 8.0;
	rot_speed = data->time.frame_time * 2.0;
	if (key == K_W)
		forward(data, move_speed);
	if (key == K_S)
		backward(data, move_speed);
	if (key == K_D)
		left(data, move_speed);
	if (key == K_A)
		right(data, move_speed);
	if (key == R_ARROW)
		rotations(data, rot_speed);
	if (key == L_ARROW)
		rotations(data, -rot_speed);
	if (key == K_ESC)
		on_destroy(data);
	return (0);
}

int	on_destroy(t_data *data)
{
	printf(RED"Game closed"WHT"\n");
	mem_clean(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, on_destroy, NULL);
	mlx_loop_hook(data->mlx, render, data);
	mlx_hook(data->win, E_KEYPRESS, 1L << 0, ft_keypress, data);
	return (0);
}