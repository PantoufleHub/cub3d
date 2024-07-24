// mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
#include "../../inc/cub3D.h"
#include <math.h>

int is_move(int x, int y , t_data *data)
{
  // NOTE: RETURN TRUE if a the next position is a '0'. False if not
  if (data->map[x][y] == '0')
    return (TRUE);
  return (FALSE);
}

int ft_keypress(int key, t_data *data)
{
  if (key == K_W)
  {
    data->player.playerCos = cos(degreetoRadiant(data->player.angle)) * SPEED;
    data->player.playerSin = sin(degreetoRadiant(data->player.angle)) * SPEED;

    data->player.newX = data->player.x + data->player.playerCos;
    data->player.newY = data->player.y + data->player.playerSin;
    if (data->map[(int)data->player.newX][(int)data->player.newY] == '0')
    {
      data->player.x = data->player.newX;
      data->player.y = data->player.newY;
    }
  }
  if (key == K_S)
  {
    data->player.playerCos = cos(degreetoRadiant(data->player.angle)) * SPEED;
    data->player.playerSin = sin(degreetoRadiant(data->player.angle)) * SPEED;

    data->player.newX = data->player.x - data->player.playerCos;
    data->player.newY = data->player.y - data->player.playerSin;
    if (data->map[(int)data->player.newX][(int)data->player.newY] == '0')
    {
      data->player.x = data->player.newX;
      data->player.y = data->player.newY;
    }
  }
  if (key == K_A)
  {
    data->player.angle -= ROTSPEED;
  }
  if (key == K_D)
  {
    data->player.angle += ROTSPEED;
  }
  render(data);
  return (0);
}

int	ft_controls(t_data *data)
{
  mlx_hook(data->mlx.mlx_win, E_KEYPRESS, 1L<<0, ft_keypress, data);
  // mlx_hook(mlx->mlx_win, 17, 0, ft_buttonquit, data);
  return (0);
}
