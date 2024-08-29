#include "../../inc/cub3D.h"

int	init_data(t_data *data)
{
	// void	*mlx;
	mlx_init(data->mlx);
    // void	*win;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, WINDOW_TITLE);
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

	// RESTE ENCORE A SET:
    // t_vectors	vec;
    // t_img_data	img;
    // int		x;
    // t_time	time;
    // t_calc_info	calc_info;
}