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
  // double time;
  // data->ref_time = init_timer();
  // time = get_time_elapse(data->ref_time);
  // data->oldTime = time;
  // data->frametime = (time - data->oldTime) / 1000.0; 
  // double rotSpeed = data->frametime * ROTSPEED;
  // double moveSpeed = data->frametime * SPEED;

  if (key == K_W)
  {
    if (data->map[(int)(data->vec.pos.x + data->vec.dir.x* SPEED)][(int)(data->vec.pos.y)] == '0')
    {
      data->vec.pos.x += data->vec.dir.x * SPEED;
    }
    if (data->map[(int)(data->vec.pos.x)][(int)(data->vec.pos.y + data->vec.dir.y * SPEED)] == '0')
    {
      data->vec.pos.y += data->vec.dir.y * SPEED;
    }
  }
  if (key == K_S)
  {
    if (data->map[(int)(data->vec.pos.x - data->vec.dir.x* SPEED)][(int)(data->vec.pos.y)] == '0')
    {
      data->vec.pos.x -= data->vec.dir.x * SPEED;
    }
    if (data->map[(int)(data->vec.pos.x)][(int)(data->vec.pos.y - data->vec.dir.y * SPEED)] == '0')
    {
	data->vec.pos.y -= data->vec.dir.y * SPEED;
    }
  }
  if (key == K_D)
  {
    double  oldDirX;
    double  oldPlaneX;

    oldDirX = data->vec.dir.x;
    data->vec.dir.x = data->vec.dir.x * cos(-ROTSPEED) - data->vec.dir.y * sin(-ROTSPEED); 
    data->vec.dir.y = oldDirX * sin(-ROTSPEED) + data->vec.dir.y * cos(-ROTSPEED);

    oldPlaneX = data->vec.plane.x ;
    data->vec.plane.x = data->vec.plane.x * cos(-ROTSPEED) - data->vec.plane.y * sin(-ROTSPEED);  
    data->vec.plane.y = oldPlaneX * sin(-ROTSPEED) + data->vec.plane.y * cos(-ROTSPEED);
 }
  if (key == K_A)
  {
    double  oldDirX;
    double  oldPlaneX;

    oldDirX = data->vec.dir.x;
    data->vec.dir.x = data->vec.dir.x * cos(ROTSPEED) - data->vec.dir.y * sin(ROTSPEED); 
    data->vec.dir.y = oldDirX * sin(ROTSPEED) + data->vec.dir.y * cos(ROTSPEED);

    oldPlaneX = data->vec.plane.x ;

    data->vec.plane.x = data->vec.plane.x * cos(ROTSPEED) - data->vec.plane.y * sin(ROTSPEED);  
    data->vec.plane.y = oldPlaneX * sin(ROTSPEED) + data->vec.plane.y * cos(ROTSPEED);
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
