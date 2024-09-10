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
	int	i;

	i = 0;
	while (i < 4)
	{
		init_texture_data(&textures[i]);
		i++;
	}
}

int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, WINDOW_TITLE);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr (data->img.img,
			&data->img.bit_per_pixel, &data->img.size_line, &data->img.endian);
	data->map = NULL;
	data->nb_rows = -1;
	init_textures(data->textures);
	data->floor_color = -1;
	data->ceiling_color = -1;
	init_render_info(data);
	return (0);
}
