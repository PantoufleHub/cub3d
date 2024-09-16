#include "../../inc/cub3D.h"

void	draw_minimap(t_data *data)
{
	int x = 0;
	int y = 0;
	int tile_size = 20;
	int nb_tile_col = 10;
	int nb_tile_row = nb_tile_col;
	double startx = (int)data->vec.pos.x - ((double)nb_tile_col / 2.0);
	double starty = (int)data->vec.pos.y - ((double)nb_tile_row / 2.0);
	while (y < nb_tile_row)
	{
		while (x < nb_tile_col)
		{
			// cadre
			if (x == 0 || y == 0 || x == nb_tile_col - 1 || y == nb_tile_row - 1)
			{
				for (int a = 0; a < tile_size; a++)
				{
					for (int b = 0; b < tile_size; b++)
					{
						my_mlx_pixel_put_blend(&data->img, MAP_X + (x * tile_size) + b, MAP_Y + (y * tile_size) + a, create_trgb(204, x * 20, y * 20, 34));
					}
				}
			}
			else
			{
				if (starty + y >= 0
					&& startx + x >= 0
					&& starty + y < data->nb_rows
					&& startx + x < (int)ft_strlen(data->map[(int)starty + y]))
				{
					if (data->map[(int)starty + y][(int)startx + x] == '1') // MUR
					{
						for (int a = 0; a < tile_size; a++)
						{
							for (int b = 0; b < tile_size; b++)
							{
								my_mlx_pixel_put_blend(&data->img, MAP_X + (x * tile_size) + b, MAP_Y + (y * tile_size) + a, 0xCC3657ba);
							}
						}
					}
					else if (data->map[(int)starty + y][(int)startx + x] == '0') // LIBRE
					{
						for (int a = 0; a < tile_size; a++)
						{
							for (int b = 0; b < tile_size; b++)
							{
								my_mlx_pixel_put_blend(&data->img, MAP_X + (x * tile_size) + b, MAP_Y + (y * tile_size) + a, 0xCCe3faff);
							}
						}
					}
					else // PAS DANS LA CARTE
					{
						for (int a = 0; a < tile_size; a++)
						{
							for (int b = 0; b < tile_size; b++)
							{
								my_mlx_pixel_put_blend(&data->img,
								MAP_X + (x * tile_size) + b,
								MAP_Y + (y * tile_size) + a,
								create_trgb(204, 90 + x, 90 + x, 90 + x));
							}
						}
					}
				}
				else // PAS DANS LA CARTE
					{
						for (int a = 0; a < tile_size; a++)
						{
							for (int b = 0; b < tile_size; b++)
							{
								my_mlx_pixel_put_blend(&data->img,
								MAP_X + (x * tile_size) + b,
								MAP_Y + (y * tile_size) + a,
								create_trgb(204, 90 + x, 90 + x, 90 + x));
							}
						}
					}
			}
			x++;
		}
		x = 0;
		y++;
	}
	// "FLECHE"
	int arrowx = MAP_X + nb_tile_col * tile_size / 2 + (data->vec.pos.x - (int)data->vec.pos.x) * tile_size;
	int arrowy = MAP_Y + nb_tile_row * tile_size / 2 + (data->vec.pos.y - (int)data->vec.pos.y) * tile_size;
	int len = (int)(tile_size / 1.5);
	while (len > 0)
	{
		my_mlx_pixel_put(
			&data->img,
			(arrowx + data->vec.dir.x * len),
			(arrowy + data->vec.dir.y * len),
			0x00FF0000);
			len--;
		my_mlx_pixel_put(
			&data->img,
			(arrowx + (-data->vec.dir.y) * len / 2),
			(arrowy + (data->vec.dir.x) * len / 2),
			0x0);
			len--;
		my_mlx_pixel_put(
			&data->img,
			(arrowx + (data->vec.dir.y) * len / 2),
			(arrowy + (-data->vec.dir.x) * len / 2),
			0x0);
			len--;
	}
}
