#include "../../inc/cub3D.h"

int	is_move(int y, int x, t_data *data)
{
	if (data->map[y][x] == '0')
		return (TRUE);
	return (FALSE);
}

void	pos_update_w(t_data **data)
{
	(*data)->player.playerCos = cos_degree((*data)->player.angle) * SPEED;
	(*data)->player.playerSin = sin_degree((*data)->player.angle) * SPEED;
	(*data)->player.newX = (*data)->player.x + (*data)->player.playerCos;
	(*data)->player.newY = (*data)->player.y + (*data)->player.playerSin;
	if (is_move((*data)->player.newY, (*data)->player.newX, (*data)))
	{
		(*data)->player.x = (*data)->player.newX;
		(*data)->player.y = (*data)->player.newY;
	}
}

void	pos_update_s(t_data **data)
{
	(*data)->player.playerCos = cos_degree((*data)->player.angle) * SPEED;
	(*data)->player.playerSin = sin_degree((*data)->player.angle) * SPEED;
	(*data)->player.newX = (*data)->player.x - (*data)->player.playerCos;
	(*data)->player.newY = (*data)->player.y - (*data)->player.playerSin;
	if (is_move((*data)->player.newY, (*data)->player.newX, (*data)))
	{
		(*data)->player.x = (*data)->player.newX;
		(*data)->player.y = (*data)->player.newY;
	}
}

int	ft_keypress(int key, t_data *data)
{
	if (key == K_W)
		pos_update_w(&data);
	if (key == K_S)
		pos_update_s(&data);
	if (key == K_A)
	{
		data->player.angle -= ROTSPEED;
		printf("Player Angle: %f\n", data->player.angle);
	}
	if (key == K_D)
	{
		data->player.angle += ROTSPEED;
		printf("Player Angle: %f\n", data->player.angle);
	}
	refresh(data);
	return (0);
}

int	ft_controls(t_data *data)
{
	mlx_hook(data->mlx.mlx_win, E_KEYPRESS, 1L << 0, ft_keypress, data);
	return (0);
}
