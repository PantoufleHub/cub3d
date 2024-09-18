/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:55:48 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 11:02:07 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
	int	*data_ptr;

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
