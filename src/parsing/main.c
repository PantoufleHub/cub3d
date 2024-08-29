#include "../../lib/mlx/mlx.h"
#include "../../lib/libft/inc/libft.h"
#include "../../inc/parsing.h"
#include "../../inc/colors.h"
#include "../../inc/cub3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data) < 0)
		return (printf(RED"Error\nCouldn't initialize data\n"WHT), EXIT_FAILURE);
	if (argc != 2)
		return (printf(RED"Error\nPlease input single .cub file\n"WHT),
			EXIT_FAILURE);
	if (parse(argv[1], &data) < 0)
		printf(RED"\n- Parsing failed -\n\n"WHT);
	else
		printf(GRN"\n- Parsing Succesful -\n\n"WHT);
	return (EXIT_SUCCESS);
}
