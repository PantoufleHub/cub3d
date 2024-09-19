/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:55:25 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 11:01:40 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief Checks if a string contains one or more of specific characters
/// @param str 
/// @param c_arr 
/// @return -1 if no, index if yes
int	c_in_str(char *str, char *c_arr)
{
	int	c_index;
	int	s_index;

	c_index = 0;
	while (c_arr[c_index])
	{
		s_index = 0;
		while (str[s_index])
		{
			if (c_arr[c_index] == str[s_index])
				return (s_index);
			s_index++;
		}
		c_index++;
	}
	return (-1);
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

int	parse(char *path, t_data *data)
{
	int		fd;
	t_list	*tmp_map;

	tmp_map = NULL;
	printf(YEL"\n[ Parsing path \""CYN"%s"YEL"\" ]\n"WHT, path);
	if (parse_path(path, &fd) < 0)
		return (-1);
	printf(YEL"\n[ Parsing file content ]\n"WHT);
	if (parse_file(fd, data, &tmp_map) < 0)
		return (ft_lstclear(&tmp_map, free), -1);
	if (!file_data_filled(data, 0))
		return (print_err(NULL, 0, ERR_MSG_MISSING));
	printf(YEL"\n[ Parsing map ]\n"WHT);
	if (parse_map(&tmp_map) < 0)
		return (ft_lstclear(&tmp_map, free), -1);
	if (get_player_data(tmp_map, data) < 0)
		return (ft_lstclear(&tmp_map, free), -1);
	set_map(tmp_map, data);
	data->nb_rows = get_nb_rows(data->map);
	ft_lstclear(&tmp_map, free);
	return (0);
}
