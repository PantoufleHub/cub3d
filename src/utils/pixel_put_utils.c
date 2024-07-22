#include "../../inc/cub3D.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}