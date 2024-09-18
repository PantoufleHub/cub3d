/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:56:01 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 14:23:42 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf(RED"Error\nPlease input single .cub file"WHT"\n"),
			EXIT_FAILURE);
	if (init_data(&data) < 0)
	{
		printf(RED"Error\nCouldn't initialize data"WHT"\n");
		mem_clean(&data);
		return (EXIT_FAILURE);
	}
	if (parse(argv[1], &data) < 0)
	{
		printf(RED"\nError\n- Parsing failed -"WHT"\n\n");
		mem_clean(&data);
		return (EXIT_FAILURE);
	}
	else
		printf(GRN"\n- Parsing Succesful -\n"CYN"Have fun!"WHT"\n");
	ft_hooks(&data);
	render(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
