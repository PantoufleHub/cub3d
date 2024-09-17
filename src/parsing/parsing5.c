#include "../../lib/mlx/mlx.h"
#include "../../lib/libft/inc/libft.h"
#include "../../inc/colors.h"
#include "../../inc/error_msg.h"
#include "../../inc/parsing.h"
#include "../../inc/cub3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	// int		index;
	char	*line_dup;

	// index = 0;
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
