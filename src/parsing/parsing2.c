#include "../../lib/mlx/mlx.h"
#include "../../lib/libft/inc/libft.h"
#include "../../inc/colors.h"
#include "../../inc/error_msg.h"
#include "../../inc/parsing.h"
#include "../../inc/cub3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	set_texture_path(int line_nb, char *line, t_data *data, char *path)
{
	if (line[0] == 'N')
	{
		if (data->textures[0].path)
		{
			printf("Texture path: %s\n", data->textures[0].path);
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		}
		return (set_data_path(line, &data->textures[0].path, path));
	}
	if (line[0] == 'E')
	{
		if (data->textures[1].path)
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		return (set_data_path(line, &data->textures[1].path, path));
	}
	if (line[0] == 'S')
	{
		if (data->textures[2].path)
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		return (set_data_path(line, &data->textures[2].path, path));
	}
	if (line[0] == 'W')
	{
		if (data->textures[3].path)
			return (print_err(line, line_nb, ERR_MSG_REDIFINING));
		return (set_data_path(line, &data->textures[3].path, path));
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
