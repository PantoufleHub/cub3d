#include "../../lib/mlx/mlx.h"
#include "../../lib/libft/inc/libft.h"
#include "../../inc/colors.h"
#include "../../inc/error_msg.h"
#include "../../inc/parsing.h"
#include "../../inc/cub3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	init_texture_data(t_texture_data *data)
{
	data->img_data = malloc(sizeof(t_img_data));
	data->img_data->addr = NULL;
	data->img_data->img = NULL;
	data->path = NULL;
	data->height = -1;
	data->width = -1;
}

/// @brief checks if the data is valid in data structure
/// @param data pointer to data structure
/// @param include_map if the map should be included in the check
/// @return returns 1 if valid 0 if not valid
int	file_data_filled(t_data *data, int include_map)
{
	if (!data)
		return (0);
	if (data->ceiling_color == -1 || data->floor_color == -1)
		return (0);
	if (!data->textures[0].path
		|| !data->textures[1].path
		|| !data->textures[2].path
		|| !data->textures[3].path)
		return (0);
	if (include_map)
	{
		if (!data->map)
			return (0);
		if (data->vec.dir.x == VEC_INIT || data->vec.dir.y == VEC_INIT
			|| data->vec.plane.x == VEC_INIT || data->vec.plane.y == VEC_INIT
			|| data->vec.pos.x == VEC_INIT || data->vec.pos.y == VEC_INIT)
			return (0);
	}
	return (1);
}

/// @brief Set player data determined by the NESW char in map
/// @param c the character in the map
/// @param col the column where c is
/// @param row the row where c is
/// @param data the map data
void	set_player_data(char c, int col, int row, t_data *data)
{
	if (c == 'N')
	{
		data->vec.dir.x = 0;
		data->vec.dir.y = -1;
		data->vec.plane.x = 0.66;
		data->vec.plane.y = 0;
	}
	if (c == 'E')
	{
		data->vec.dir.x = 1;
		data->vec.dir.y = 0;
		data->vec.plane.x = 0;
		data->vec.plane.y = 0.66;
	}
	if (c == 'S')
	{
		data->vec.dir.x = 0;
		data->vec.dir.y = 1;
		data->vec.plane.x = -0.66;
		data->vec.plane.y = 0;
	}
	if (c == 'W')
	{
		data->vec.dir.x = -1;
		data->vec.dir.y = 0;
		data->vec.plane.x = 0;
		data->vec.plane.y = -0.66;
	}
	data->vec.pos.x = (double)(col + 0.5);
	data->vec.pos.y = (double)(row + 0.5);
}

int	get_player_data(t_list *map, t_data *data)
{
	int			row;
	int			col;
	char		*line;
	static int	player_count = 0;

	row = 0;
	while (map)
	{
		line = (char *)map->content;
		col = 0;
		while (line[col])
		{
			if (c_is_in(line[col], "NESW"))
			{
				player_count++;
				if (player_count > 1)
					return (print_err(NULL, 0, ERR_MSG_MULTI_SPAWN));
				set_player_data(line[col], col, row, data);
			}
			col++;
		}
		row++;
		map = map->next;
	}
	if (player_count < 1)
		return (print_err(NULL, 0, ERR_MSG_NO_SPAWN));
	return (0);
}

void	get_adjacents(char *lines[3], char (*adjacents)[4], int index)
{
	(*adjacents)[1] = lines[1][index + 1];
	if (index > 0 && lines[1][index - 1])
		(*adjacents)[3] = lines[1][index - 1];
	else
		(*adjacents)[3] = 0;
	if (lines[0] && ft_strlen(lines[0]) >= (size_t)index)
		(*adjacents)[0] = lines[0][index];
	else
		(*adjacents)[0] = 0;
	if (lines[2] && ft_strlen(lines[2]) >= (size_t)index)
		(*adjacents)[2] = lines[2][index];
	else
		(*adjacents)[2] = 0;
}
