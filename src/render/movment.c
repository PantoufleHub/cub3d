// mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
#include "../../inc/cub3D.h"

int ft_keypress(int key, t_data *data)
{
  double movespeed;
  double rotSpeed;

  movespeed = data->time.FrameTime * 5.0;
  rotSpeed  = data->time.FrameTime * 3.0;
  if (key == K_W)
  {
    if (data->map[(int)(data->vec.pos.x + data->vec.dir.x* movespeed )][(int)(data->vec.pos.y)] == '0')
      data->vec.pos.x += data->vec.dir.x * movespeed;
    if (data->map[(int)(data->vec.pos.x)][(int)(data->vec.pos.y + data->vec.dir.y * movespeed)] == '0')
      data->vec.pos.y += data->vec.dir.y * movespeed;
	printf("Pos x %lf\nPos Y %lf\n",data->vec.pos.x,data->vec.pos.y);
  }
  if (key == K_S)
  {
    if (data->map[(int)(data->vec.pos.x - data->vec.dir.x* movespeed)][(int)(data->vec.pos.y)] == '0')
      data->vec.pos.x -= data->vec.dir.x * movespeed;
    if (data->map[(int)(data->vec.pos.x)][(int)(data->vec.pos.y - data->vec.dir.y * movespeed)] == '0')
      data->vec.pos.y -= data->vec.dir.y * movespeed;
	printf("Pos x %lf\nPos Y %lf\n",data->vec.pos.x,data->vec.pos.y);
  }
  if (key == K_D)
    rotations(data,-rotSpeed);
  if (key == K_A)
    rotations(data, rotSpeed);
  render(data);
  return (0);
}

int	ft_hooks(t_data *data)
{
  mlx_loop_hook(data->mlx.mlx,render ,data);
  mlx_hook(data->mlx.mlx_win, E_KEYPRESS, 1L<<0, ft_keypress, data);
  // mlx_hook(mlx->mlx_win, 17, 0, ft_buttonquit, data);
  return (0);
}
