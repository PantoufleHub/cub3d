#include "../../lib/mlx/mlx.h"
#include "../../lib/libft/inc/libft.h"
#include "../../inc/colors.h"
#include "../../inc/error_msg.h"
#include "../../inc/parsing.h"
#include "../../inc/cub3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	set_data_path(char *line, char **ptr, char *path)
{
	// CHECK SI CA FOIRE PTETRE?
	// line_nb = 0; // pr erreur
	*ptr = ft_strdup(path);
	printf(GRN"✔ Assigned to "MAG"%c%c"GRN" image: "MAG"%s\n"WHT,
		line[0], line[1], path);
	return (0);
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