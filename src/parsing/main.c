#include "../../lib/mlx/mlx.h"
#include "../../lib/libft/inc/libft.h"
#include "../../inc/parsing.h"
#include "../../inc/colors.h"
#include "../../inc/cub3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char **argv)
{
	int parse_status = 0;
	t_data data;

	if (init_data(&data) < 0)
	{
		printf(RED"Error\nCouldn't initialize data\n"WHT);
		return (EXIT_FAILURE);
	}
	if (argc != 2)
	{
		printf(RED"Error\nPlease input single .cub file\n"WHT);
		return (EXIT_FAILURE);
	}
	parse_status = parse(argv[1], &data);
	if (parse_status < 0)
		printf(RED"\n- Parsing failed -\n\n"WHT);
	else
		printf(GRN"\n- Parsing Succesful -\n\n"WHT);
	return (EXIT_SUCCESS);
}
