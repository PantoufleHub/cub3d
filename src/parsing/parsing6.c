/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:55:20 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 11:02:13 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	init_texture_data(t_texture_data *data)
{
	data->img_data = malloc(sizeof(t_img_data));
	data->img_data->addr = NULL;
	data->img_data->img = NULL;
	data->path = NULL;
	data->height = -1;
	data->width = -1;
}

void	help_set_player_data(t_data *data, double vectors[4])
{
	data->vec.dir.x = vectors[0];
	data->vec.dir.y = vectors[1];
	data->vec.plane.x = vectors[2];
	data->vec.plane.y = vectors[3];
}

/// @brief Set player data determined by the NESW char in map
/// @param c the character in the map
/// @param col the column where c is
/// @param row the row where c is
/// @param data the map data
void	set_player_data(char c, int col, int row, t_data *data)
{
	if (c == 'N')
		help_set_player_data(data, (double [4]){0, -1, 0.66, 0});
	if (c == 'E')
		help_set_player_data(data, (double [4]){1, 0, 0, 0.66});
	if (c == 'S')
		help_set_player_data(data, (double [4]){0, 1, -0.66, 0});
	if (c == 'W')
		help_set_player_data(data, (double [4]){-1, 0, 0, -0.66});
	data->vec.pos.x = (double)(col + 0.5);
	data->vec.pos.y = (double)(row + 0.5);
}

int	patati(int player_count)
{
	if (player_count < 1)
		return (print_err(NULL, 0, ERR_MSG_NO_SPAWN));
	return (0);
}

int	get_player_data(t_list *map, t_data *data)
{
	int			row;
	char		*line;
	int			col;
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
	return (patati(player_count));
}
