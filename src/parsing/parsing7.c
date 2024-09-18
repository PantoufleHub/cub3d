/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:55:57 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 11:02:16 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
