// mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
#include "../../inc/cub3D.h"

int	ft_keypress(int key, t_data *data)
{
	double	movespeed;
	double	rotSpeed;

	movespeed = data->time.FrameTime * 8.0;
	rotSpeed = data->time.FrameTime * 10.0;
	if (key == K_W)
	{
		if (data->map[(int)(data->vec.pos.y + data->vec.dir.y * movespeed)]
			[(int)(data->vec.pos.x)] == '0')
			data->vec.pos.y += data->vec.dir.y * movespeed;
		if (data->map[(int)(data->vec.pos.y)]
			[(int)(data->vec.pos.x + data->vec.dir.x * movespeed)] == '0')
			data->vec.pos.x += data->vec.dir.x * movespeed;
	}
	if (key == K_S)
	{
		if (data->map[(int)(data->vec.pos.y - data->vec.dir.y * movespeed)]
			[(int)(data->vec.pos.x)] == '0')
			data->vec.pos.y -= data->vec.dir.y * movespeed;
		if (data->map[(int)(data->vec.pos.y)]
			[(int)(data->vec.pos.x - data->vec.dir.x * movespeed)] == '0')
			data->vec.pos.x -= data->vec.dir.x * movespeed;
	}
	if (key == K_D)
		rotations(data, -rotSpeed);
	if (key == K_A)
		rotations(data, rotSpeed);
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
