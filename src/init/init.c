#include "../../inc/cub3D.h"


void	init_render_info(t_data *data)
{
    data->vec.pos.x = VEC_NOT_SET;
    data->vec.pos.y = VEC_NOT_SET;
    data->vec.dir.x = VEC_NOT_SET;
    data->vec.dir.y = VEC_NOT_SET;
    data->vec.plane.x = VEC_NOT_SET;
    data->vec.plane.y = VEC_NOT_SET;
    data->time.ref_time = init_timer();
    data->time.oldTime = 0;
    data->time.time = 0;
    data->x = 0;
}

int	init_data(t_data *data)
{
	// void	*mlx;
	data->mlx = mlx_init();
    // void	*win;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, WINDOW_TITLE);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr (data->img.img,
	    &data->img.bit_per_pixel, &data->img.size_line, &data->img.endian);
    // char	**map;
	data->map = NULL;
    // t_texture_data	*textures[4]; // N E S W
	data->textures[0] = NULL;
	data->textures[1] = NULL;
	data->textures[2] = NULL;
	data->textures[3] = NULL;
    // int		floor_color;
	data->floor_color = -1;
    // int		ceiling_color;
	data->ceiling_color = -1;
}
