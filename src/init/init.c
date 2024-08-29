#include "../../inc/cub3D.h"


void	init_render_info(t_data *data)
{
	data->vec.pos.x = VEC_INIT;
	data->vec.pos.y = VEC_INIT;
	data->vec.dir.x = VEC_INIT;
	data->vec.dir.y = VEC_INIT;
	data->vec.plane.x = VEC_INIT;
	data->vec.plane.y = VEC_INIT;
	data->time.ref_time = init_timer();
	data->time.oldTime = 0;
	data->time.time = 0;
	data->x = 0;
}

void	init_textures(t_texture_data textures[4])
{
	textures[0].path = NULL;
	textures[0].img = NULL;
	textures[0].width = -1;
	textures[0].height = -1;
	textures[1].path = NULL;
	textures[1].img = NULL;
	textures[1].width = -1;
	textures[1].height = -1;
	textures[2].path = NULL;
	textures[2].img = NULL;
	textures[2].width = -1;
	textures[2].height = -1;
	textures[3].path = NULL;
	textures[3].img = NULL;
	textures[3].width = -1;
	textures[3].height = -1;
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
	init_textures(data->textures);
	// int		floor_color;
	data->floor_color = -1;
	// int		ceiling_color;
	data->ceiling_color = -1;
	init_render_info(data);
	return (0);
}
