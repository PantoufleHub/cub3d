/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:56:15 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 10:56:16 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	draw_map_tile(t_data *data, int tile_size, int coords[2], int color)
{
	int	a;
	int	b;
	int	x;
	int	y;

	a = 0;
	b = 0;
	while (a < tile_size)
	{
		while (b < tile_size)
		{
			x = MAP_X + (coords[0] * tile_size) + b;
			y = MAP_Y + (coords[1] * tile_size) + a;
			my_mlx_pixel_put_blend(&data->img, x, y, color);
			b++;
		}
		b = 0;
		a++;
	}
}

void	draw_map_arrow(t_data *data, int cols, int rows, int tile_size)
{
	int	arrowx;
	int	arrowy;
	int	len;

	len = (int)(tile_size / 1.5);
	arrowy = MAP_Y + rows * tile_size / 2
		+ (data->vec.pos.y - (int)data->vec.pos.y) * tile_size;
	arrowx = MAP_X + cols * tile_size / 2
		+ (data->vec.pos.x - (int)data->vec.pos.x) * tile_size;
	while (len > 0)
	{
		my_mlx_pixel_put(
			&data->img, (arrowx + data->vec.dir.x * len),
			(arrowy + data->vec.dir.y * len), 0x00FF0000);
		my_mlx_pixel_put(
			&data->img, (arrowx + (-data->vec.dir.y) * len / 3),
			(arrowy + (data->vec.dir.x) * len / 3), 0x0);
		my_mlx_pixel_put(
			&data->img, (arrowx + (data->vec.dir.y) * len / 3),
			(arrowy + (-data->vec.dir.x) * len / 3), 0x0);
		len--;
	}
}

void	norminette_map(t_data *data, int x, int y, double startxy[2])
{
	if (x == 0 || y == 0 || x == MAP_COLS - 1 || y == MAP_ROWS - 1)
		draw_map_tile(data, MAP_TILE_SIZE, (int [2]){x, y},
			MAP_BORDER_COLOR | MAP_TRANSPARENCY);
	else
	{
		if (startxy[1] + y >= 0 && startxy[0] + x >= 0
			&& startxy[1] + y < data->nb_rows
			&& startxy[0] + x < (int)ft_strlen(data->map[(int)startxy[1] + y]))
		{
			if (data->map[(int)startxy[1] + y][(int)startxy[0] + x] == '1')
				draw_map_tile(data, MAP_TILE_SIZE, (int [2]){x, y},
					MAP_WALL_COLOR | MAP_TRANSPARENCY);
			else if (data->map[(int)startxy[1] + y]
				[(int)startxy[0] + x] == '0')
				draw_map_tile(data, MAP_TILE_SIZE, (int [2]){x, y},
					MAP_EMPTY_COLOR | MAP_TRANSPARENCY);
			else
				draw_map_tile(data, MAP_TILE_SIZE, (int [2]){x, y},
					MAP_VOID_COLOR | MAP_TRANSPARENCY);
		}
		else
			draw_map_tile(data, MAP_TILE_SIZE, (int [2]){x, y},
				MAP_VOID_COLOR | MAP_TRANSPARENCY);
	}
}

void	draw_minimap(t_data *data)
{
	int		x;
	int		y;
	double	startx;
	double	starty;

	x = 0;
	y = 0;
	startx = (int)data->vec.pos.x - ((double)MAP_COLS / 2.0);
	starty = (int)data->vec.pos.y - ((double)MAP_ROWS / 2.0);
	while (y < MAP_ROWS)
	{
		while (x < MAP_COLS)
		{
			norminette_map(data, x, y, (double [2]){startx, starty});
			x++;
		}
		x = 0;
		y++;
	}
	draw_map_arrow(data, MAP_COLS, MAP_ROWS, MAP_TILE_SIZE);
}
