#include "../../lib/mlx/mlx.h"
#include "../../lib/libft/inc/libft.h"
#include "../../inc/colors.h"
#include "../../inc/error_msg.h"
#include "../../inc/parsing.h"
#include "../../inc/cub3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ----- CHECKLIST -----
// .CUB FILE EXISTS, ACCESS
// ALL PATHS, (NO, SO, WE, EA, F, C) no dup, syntax, correct values
// MAP (SURROUNDED, UNKNOWN CHARACTERS, 1 PLAYER)

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

/// @brief Checks if c is in a given array
/// @param c 
/// @param c_arr 
/// @return 
int	c_is_in(char c, char *c_arr)
{
	int	index;

	index = 0;
	while (c_arr[index])
	{
		if (c == c_arr[index])
			return (1);
		index++;
	}
	return (0);
}

int	str_contains_only(char *str, char *c_arr)
{
	int	s_index;
	int	found;
	int	c_index;

	s_index = 0;
	while (str[s_index])
	{
		found = 0;
		c_index = 0;
		while (c_arr[c_index])
		{
			if (str[s_index] == c_arr[c_index])
			{
				found = 1;
				break ;
			}
			c_index++;
		}
		if (!found)
			return (0);
		s_index++;
	}
	return (1);
}

void	print_no_nl(char *line)
{
	int	index;

	index = 0;
	while (line[index] && line[index] != '\n')
	{
		printf("%c", line[index]);
		index++;
	}
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	print_err(char *line, int line_nb, char *msg)
{
	if (!line)
	{
		printf(RED"Error\n%s\n", msg);
		return (-1);
	}
	printf(RED"Error\nLine %d: %s\n["WHT, line_nb, msg);
	print_no_nl(line);
	printf(RED"]\n"WHT);
	return (-1);
}

void	init_texture_data(t_texture_data *data)
{
	data->img_data = malloc(sizeof(t_img_data));
	data->img_data->addr = NULL;
	data->img_data->img = NULL;
	data->path = NULL;
	data->height = -1;
	data->width = -1;
}

// void	init_data(t_data *data)
// {
// 	data->map = NULL;
// 	data->ceiling_color = -1;
// 	data->floor_color = -1;
// 	data->map = NULL;
// 	data->textures[0] = malloc(sizeof (t_texture_data));
// 	data->textures[1] = malloc(sizeof (t_texture_data));
// 	data->textures[2] = malloc(sizeof (t_texture_data));
// 	data->textures[3] = malloc(sizeof (t_texture_data));
// 	init_texture_data(data->textures[0]);
// 	init_texture_data(data->textures[1]);
// 	init_texture_data(data->textures[2]);
// 	init_texture_data(data->textures[3]);
	// data->player_data[0] = -1;
	// data->player_data[1] = -1;
	// data->player_data[2] = -1;
	// data->player_data[3] = -1;
// }

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
		data->vec.dir.x = -1;
		data->vec.dir.y = 0;
		data->vec.plane.x = 0;
		data->vec.plane.y = 0.66;
	}
	if (c == 'E')
	{
		data->vec.dir.x = 0;
		data->vec.dir.y = 1;
		data->vec.plane.x = 0.66;
		data->vec.plane.y = 0;
	}
	if (c == 'S')
	{
		data->vec.dir.x = 1;
		data->vec.dir.y = 0;
		data->vec.plane.x = 0;
		data->vec.plane.y = -0.66;
	}
	if (c == 'W')
	{
		data->vec.dir.x = 0;
		data->vec.dir.y = -1;
		data->vec.plane.x = -0.66;
		data->vec.plane.y = 0;
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

int	map_char_valid(char c, char adjacent[4])
{
	static int	has_player = 0;

	if (c_is_in(c, "NESW") && has_player)
		return (0);
	if (c_is_in(c, "NESW"))
		has_player = 1;
	if (!c_is_in(c, "01NESW "))
		return (0);
	if ((c == '0' || c_is_in(c, "NESW"))
		&& ((adjacent[0] == 0 || adjacent[0] == ' ')
			|| (adjacent[1] == 0 || adjacent[1] == ' ')
			|| (adjacent[2] == 0 || adjacent[2] == ' ')
			|| (adjacent[3] == 0 || adjacent[3] == ' ')))
		return (0);
	return (1);
}

int	parse_map3(char *prev_l, char *line, char *next_l, int *status)
{
	int		index;
	char	adjacents[4];

	index = 0;
	while (line && line[index])
	{
		get_adjacents((char *[3]){prev_l, line, next_l}, &adjacents, index);
		if (!map_char_valid(line[index], adjacents))
		{
			*status = -1;
			printf(RED);
		}
		else if (line[index] == '1')
			printf(GRN);
		else if (c_is_in(line[index], "NESW"))
			printf(CYN);
		else
			printf(WHT);
		printf("%c"WHT, line[index]);
		index++;
	}
	printf("\n");
	return (0);
}

int	parse_map2(t_list *prev_line, t_list *curr_line, int *status)
{
	char	*prev_l;
	char	*line;
	char	*next_l;

	line = (char *)curr_line->content;
	prev_l = NULL;
	if (prev_line)
		prev_l = (char *)(prev_line->content);
	next_l = NULL;
	if (curr_line->next)
		next_l = (char *)(curr_line->next->content);
	if (!line)
		return (print_err(NULL, 0, ERR_MSG_MAP));
	if (parse_map3(prev_l, line, next_l, status) < 0)
		return (-1);
	return (0);
}

int	parse_map(t_list **map)
{
	t_list		*previous_line;
	static int	status = 0;
	t_list		*tmp_map;

	tmp_map = *map;
	if (!tmp_map)
		return (print_err(NULL, 0, ERR_MSG_MAP));
	previous_line = NULL;
	while (tmp_map)
	{
		if (parse_map2(previous_line, tmp_map, &status) < 0)
			return (-1);
		previous_line = tmp_map;
		tmp_map = (tmp_map)->next;
	}
	return (status);
}

int	read_map(int line_nb, char *line, t_list **map)
{
	int		index;
	char	*line_dup;

	index = 0;
	if (line && line[ft_strlen(line) - 1] == '\n')
	{
		line_dup = malloc(ft_strlen(line));
		if (!line_dup)
			return (print_err(NULL, line_nb, ERR_MSG_MALLOC));
		ft_strlcpy(line_dup, line, ft_strlen(line));
	}
	else
		line_dup = ft_strdup(line);
	ft_lstadd_back(map, ft_lstnew(line_dup));
	return (0);
}

int	actually_set_color(int line_nb, char *line, int *data_ptr, int rgb[3])
{
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255
		|| rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		return (print_err(line, line_nb, ERR_MSG_255));
	*data_ptr = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	printf(GRN"✔ Assigned to "MAG"%c"GRN"  color: "WHT"R"GRN"["MAG"%*d"GRN"]"
		" "WHT"G"GRN"["MAG"%*d"GRN"] "WHT"B"GRN"["MAG"%*d"GRN"]\n"WHT,
		line[0],
		3, get_r(*data_ptr),
		3, get_g(*data_ptr),
		3, get_b(*data_ptr));
	return (0);
}

int	set_data_color(int line_nb, char *line, int *data_ptr)
{
	int	rgb[3];
	int	rgb_i;
	int	index;

	index = 0;
	rgb_i = 0;
	while (rgb_i < 3)
	{
		rgb[rgb_i] = 0;
		while (line[index])
		{
			index++;
			if (line[index] == ',')
				break ;
			if (ft_isdigit(line[index]))
			{
				rgb[rgb_i] *= 10;
				rgb[rgb_i] += line[index] - '0';
			}
		}
		rgb_i++;
	}
	return (actually_set_color(line_nb, line, data_ptr, rgb));
}

int	set_color(int line_nb, char *line, t_data *data)
{
	int	index;
	int	*data_ptr;

	index = 0;
	if (line[0] == 'F')
		data_ptr = &data->floor_color;
	else if (line[0] == 'C')
		data_ptr = &data->ceiling_color;
	else
		return (print_err(line, line_nb, "UHMM COLOR MUCH?"));
	if (*data_ptr != -1)
		return (print_err(line, line_nb, ERR_MSG_REDIFINING));
	return (set_data_color(line_nb, line, data_ptr));
}

/// WE MUST PLEASE THE NORMINETTE GODS
void	save_spacelolhaha(int (*pouet)[3])
{
	(*pouet)[0] = 1;
	(*pouet)[1] = 0;
	(*pouet)[2] = 0;
}

// V 0: index, 1:nb_commas, 2: nb_nums
int	get_color(int line_nb, char *line, t_data *data)
{
	int	v[3];

	save_spacelolhaha(&v);
	while (line[v[0]] && line[v[0]] != '\n')
	{
		if (!ft_isdigit(line[v[0]]) && !is_space(line[v[0]])
			&& line[v[0]] != ',')
			return (print_err(line, line_nb, ERR_MSG_TOKEN));
		if (line[v[0]] == ',' && v[1] >= v[2])
			return (print_err(line, line_nb, ERR_MSG_FORMAT));
		if (line[v[0]] == ',')
			v[1]++;
		else if (ft_isdigit(line[v[0]]) && !ft_isdigit(line[v[0] - 1]))
			v[2]++;
		else if (ft_isdigit(line[v[0]]) && !ft_isdigit(line[v[0] - 1])
			&& v[2] != v[1])
			return (print_err(line, line_nb, ERR_MSG_FORMAT));
		if (v[2] > v[1] + 1)
			return (print_err(line, line_nb, ERR_MSG_FORMAT));
		v[0]++;
	}
	if (v[2] != 3 || v[1] != 2)
		return (print_err(line, line_nb, ERR_MSG_FORMAT));
	return (set_color(line_nb, line, data));
}

int	set_data_path(int line_nb, char *line, char **ptr, char *path)
{
	// CHECK SI CA FOIRE PTETRE?
	line_nb = 0; // pr erreur
	*ptr = ft_strdup(path);
	printf(GRN"✔ Assigned to "MAG"%c%c"GRN" image: "MAG"%s\n"WHT,
		line[0], line[1], path);
	return (0);
}

int	set_texture_path(int line_nb, char *line, t_data *data, char *path)
{
	if (line[0] == 'N')
	{
		if (data->textures[0].path)
		{
			printf("Texture path: %s\n", data->textures[0].path);
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		}
		return (set_data_path(line_nb, line, &data->textures[0].path, path));
	}
	if (line[0] == 'E')
	{
		if (data->textures[1].path)
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		return (set_data_path(line_nb, line, &data->textures[1].path, path));
	}
	if (line[0] == 'S')
	{
		if (data->textures[2].path)
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		return (set_data_path(line_nb, line, &data->textures[2].path, path));
	}
	if (line[0] == 'W')
	{
		if (data->textures[3].path)
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		return (set_data_path(line_nb, line, &data->textures[3].path, path));
	}
	return (print_err(line, line_nb, "Error assigning texture path"));
}

int	open_texture_path(int line_nb, char *line, t_data *data, char *path)
{
	t_texture_data	*texture;

	if (access(path, F_OK) < 0)
		return (print_err(line, line_nb, ERR_MSG_NOT_EXIST));
	if (access(path, R_OK) < 0)
		return (print_err(line, line_nb, ERR_MSG_READ_FILE));
	if (ft_strlen(path) < 4
		|| ft_strncmp(".xpm", path + ft_strlen(path) - 4, 4))
		return (print_err(line, line_nb, ERR_MSG_FILE_TYPE));
	if (line[0] == 'N')
		texture = &data->textures[0];
	if (line[0] == 'E')
		texture = &data->textures[1];
	if (line[0] == 'S')
		texture = &data->textures[2];
	if (line[0] == 'W')
		texture = &data->textures[3];
	texture->img_data->img = mlx_xpm_file_to_image(data->mlx, path,
			&(texture->width), &(texture->height));
	if (!texture->img_data->img)
		return (print_err(line, line_nb, ERR_MSG_INVALID_XPM));
	texture->img_data->addr = mlx_get_data_addr(texture->img_data->img,
		&texture->img_data->bit_per_pixel, &texture->img_data->size_line,
		&texture->img_data->endian);
	return (set_texture_path(line_nb, line, data, path));
}

int	get_texture_path(int line_nb, char *line, t_data *data)
{
	int		p_i;
	int		l_i;
	char	path[2048];

	l_i = 2;
	p_i = 0;
	while (line[l_i] && is_space(line[l_i + p_i]))
		l_i++;
	if (!line[l_i] || line[l_i] == '\n')
		return (print_err(line, line_nb, ERR_MSG_EXPECTED_VALUE));
	while (line[l_i + p_i] && line[l_i + p_i] != '\n'
		&& !is_space(line[l_i + p_i]))
	{
		path[p_i] = line[l_i + p_i];
		p_i++;
		if (p_i >= 2047)
			return (print_err(line, line_nb, ERR_MSG_PATH_SIZE));
	}
	while (line[l_i + p_i] && is_space(line[l_i + p_i]))
		l_i++;
	if (line[l_i + p_i] && line[l_i + p_i] != '\n')
		return (print_err(line, line_nb, ERR_MSG_MULTIPLE_VALUE));
	path[p_i] = 0;
	return (open_texture_path(line_nb, line, data, path));
}

int	interpret_line_var(int line_nb, char *line, t_data *data)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2))
	{
		if (!line[2] || line[2] == '\n')
			return (print_err(line, line_nb, ERR_MSG_EXPECTED_VALUE));
		if (!is_space(line[2]))
			return (print_err(line, line_nb, ERR_MSG_TOKEN));
		return (get_texture_path(line_nb, line, data));
	}
	if (!ft_strncmp(line, "C", 1) || !ft_strncmp(line, "F", 1))
	{
		if (!line[1] || line[1] == '\n')
			return (print_err(line, line_nb, ERR_MSG_EXPECTED_VALUE));
		if (!is_space(line[1]))
			return (print_err(line, line_nb, ERR_MSG_TOKEN));
		return (get_color(line_nb, line, data));
	}
	print_err(line, line_nb, ERR_MSG_TOKEN);
	return (-1);
}

int	interpret_line(int line_nb, char *line, t_data *data, t_list **map)
{
	static int		parse_map = 0;

	if (!parse_map && file_data_filled(data, 0))
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			return (0);
		printf(YEL"\n[ Parsing map ]\n"WHT);
		parse_map = 1;
	}
	if (parse_map)
		return (read_map(line_nb, line, map));
	else
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			return (0);
		return (interpret_line_var(line_nb, line, data));
	}
}

int	parse_file(int fd, t_data *data, t_list **map)
{
	char	*line;
	int		line_nb;

	line = get_next_line(fd);
	line_nb = 1;
	while (line)
	{
		if (interpret_line(line_nb, line, data, map) < 0)
		{
			free(line);
			return (-1);
		}
		line_nb++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse_path(char *path, int *fd)
{
	int	new_fd;
	int	path_len;

	path_len = ft_strlen(path);
	if (path_len < 4 || ft_strncmp(path + path_len - 4, ".cub", 4))
	{
		printf(RED"Error\nInvalid file name\n"WHT);
		return (-1);
	}
	else
		printf(GRN"✔ Valid file name\n"WHT);
	new_fd = open(path, O_RDONLY);
	if (new_fd == -1)
	{
		printf(RED"Error\nUnable to open file\n"WHT);
		return (-1);
	}
	else
		printf(GRN"✔ File succesfully opened\n"WHT);
	*fd = new_fd;
	return (0);
}

int	set_map(t_list *map, t_data *data)
{
	int	map_size;
	int	nb;

	map_size = ft_lstsize(map);
	// printf("Size: %d\n", map_size);
	data->map = malloc(sizeof(char *) * (ft_lstsize(map) + 1));
	data->map[map_size] = NULL;
	nb = 0;
	while (map)
	{
		if (c_in_str((char *)map->content, "NESW") > -1)
			((char *)map->content)[c_in_str((char *)map->content, "NESW")]
				= '0';
		data->map[nb] = ft_strdup((char *)(map->content));
		map = map->next;
		nb++;
	}
	return (0);
}

int	get_nb_rows(char **map)
{
	int	nb;

	nb = 0;
	while (map && map[nb])
		nb++;
	return (nb);
}

int	parse(char *path, t_data *data)
{
	int				fd;
	static t_list	*tmp_map = NULL;

	printf(YEL"\n[ Parsing path \""CYN"%s"YEL"\" ]\n"WHT, path);
	if (parse_path(path, &fd) < 0)
		return (-1);
	printf(YEL"\n[ Parsing file content ]\n"WHT);
	if (parse_file(fd, data, &tmp_map) < 0)
		return (-1);
	if (!file_data_filled(data, 0))
		return (print_err(NULL, 0, ERR_MSG_MISSING));
	if (parse_map(&tmp_map) < 0)
		return (-1);
	if (get_player_data(tmp_map, data) < 0)
		return (-1);
	set_map(tmp_map, data);
	data->nb_rows = get_nb_rows(data->map);
	return (0);
}
