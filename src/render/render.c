#include "../../inc/cub3D.h"

void	render_column(t_line wall, t_data *data)
{
	t_line	ceiling;
	t_line	floor;
	double	step;
	double	texPos;
	int		y;

	ceiling.drawStart = 0;
	ceiling.drawEnd = wall.drawStart;
	floor.drawStart = wall.drawEnd;
	floor.drawEnd = HEIGHT;
	pixel_put_line(data->img, data->x, ceiling, data->ceiling_color);
	step = 1.0 * (double)data->textures[data->calc_info.wall_side].height
		/ (double)(HEIGHT / data->calc_info.perpWallDist);
	texPos = (double)((double)wall.drawStart - HEIGHT
			/ 2 + (double)(HEIGHT / data->calc_info.perpWallDist) / 2) * step;
	y = wall.drawStart;
	while (y < wall.drawEnd)
	{
		int texY = (int)texPos;
		int rev_pix = data->textures[data->calc_info.wall_side].width * texY;// + data->calc_info.tex_x;
		rev_pix += data->textures[data->calc_info.wall_side].width * data->textures[data->calc_info.wall_side].height + data->textures[data->calc_info.wall_side].width;
		texPos += step;
		my_mlx_pixel_put(&data->img, data->x, y,
			((int *)(data->textures[data->calc_info.wall_side].img_data->addr))
		[data->textures[data->calc_info.wall_side].width * texY + ((data->textures[data->calc_info.wall_side].width - data->calc_info.tex_x) - 1)]);
		y++;
	}
	pixel_put_line(data->img, data->x, floor, data->floor_color);
}

// EXCUSE MOI LE CODE EST DEGEU C'EST SURTOUT POUR TESTER
void	draw_minimap(t_data *data)
{
	int x = 0;
	int y = 0;
	// int c = 0xAA000000;
	int tile_size = 20;

	// MAP NORMALE ENTIERE
	// while (y < data->nb_rows * tile_size)
	// {
	// 	while (x < (int)ft_strlen(data->map[y / tile_size]) * tile_size)
	// 	{
	// 		if (data->map[y / tile_size][x / tile_size] == '1')
	// 		{
	// 			// mlx_pixel_put(data->mlx, data->win, MAP_X + x, MAP_Y + y, 0x66111111);
	// 			my_mlx_pixel_put(&data->img, MAP_X + x, MAP_Y + y, 0x00222222);
	// 		}
	// 		else if (data->map[y / tile_size][x / tile_size] == '0')
	// 			my_mlx_pixel_put(&data->img, MAP_X + x, MAP_Y + y, 0x00CCCCCC);
	// 			// mlx_pixel_put(data->mlx, data->win, MAP_X + x, MAP_Y + y, c);
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
	// "FLECHE"
	// int startx = MAP_X + data->vec.pos.x * tile_size;
	// int starty = MAP_Y + data->vec.pos.y * tile_size;
	// int len = (int)(tile_size / 1.5);
	// while (len > 0)
	// {
	// 	my_mlx_pixel_put(
	// 		&data->img,
	// 		(startx + data->vec.dir.x * len),
	// 		(starty + data->vec.dir.y * len),
	// 		0x00FF0000);
	// 		len--;
	// 	my_mlx_pixel_put(
	// 		&data->img,
	// 		(startx + (-data->vec.dir.y) * len / 2),
	// 		(starty + (data->vec.dir.x) * len / 2),
	// 		0x0);
	// 		len--;
	// 	my_mlx_pixel_put(
	// 		&data->img,
	// 		(startx + (data->vec.dir.y) * len / 2),
	// 		(starty + (-data->vec.dir.x) * len / 2),
	// 		0x0);
	// 		len--;
	// }

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

	// mlx_pixel_put(data->mlx, data->win, MAP_X + data->vec.pos.x * tile_size + x - x/2, MAP_Y + data->vec.pos.y * tile_size + y - y/2, 0x00FF0000);
}

int	render(t_data *data)
{
	int		side;
	t_line	wall;

	data->x = 0;
	data->time.oldTime = data->time.time;
	data->time.time = get_time_elapse(data->time.ref_time) / 1000.0;
	data->time.FrameTime = (data->time.time - data->time.oldTime);
	while (data->x < WIDTH)
	{
		data->calc_info = get_calc_info(data->x, data->vec.dir, data->vec.plane,
				data->vec.pos);
		side = dda(&data->calc_info, data);
		data->calc_info.perpWallDist = get_wall_dist(side, data->calc_info);
		wall = get_line_height(data->calc_info.perpWallDist);
		if (side == 0)
			data->calc_info.wall_x = data->vec.pos.y
				+ data->calc_info.perpWallDist * data->calc_info.rayDirY;
		else
			data->calc_info.wall_x = data->vec.pos.x
				+ data->calc_info.perpWallDist * data->calc_info.rayDirX;
		data->calc_info.wall_x = (fmod(data->calc_info.wall_x, 1.0));
		set_wallside(data, side);
		data->calc_info.tex_x = (int)(data->calc_info.wall_x
				* (double)(data->textures[data->calc_info.wall_side].width));
		if (side == 0 && data->calc_info.rayDirX > 0)
			data->calc_info.tex_x = data->textures
			[data->calc_info.wall_side].width - data->calc_info.tex_x - 1;
		if (side == 1 && data->calc_info.rayDirY < 0)
			data->calc_info.tex_x = data->textures
			[data->calc_info.wall_side].width - data->calc_info.tex_x - 1;
		render_column(wall, data);
		data->x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
