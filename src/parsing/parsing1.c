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
	printf(YEL"\n[ Parsing map ]\n"WHT);
	if (parse_map(&tmp_map) < 0)
		return (-1);
	if (get_player_data(tmp_map, data) < 0)
		return (-1);
	set_map(tmp_map, data);
	data->nb_rows = get_nb_rows(data->map);
	return (0);
}
