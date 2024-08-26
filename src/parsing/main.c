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
	t_map_data data;
	data.mlx = mlx_init();

	if (argc != 2)
	{
		printf("Error\nPlease input single .cub file\n");
		return (1);
	}
	parse_status = parse(argv[1], &data);
	if (parse_status < 0)
		printf(RED"\n- Parsing failed -\n\n"WHT);
	else
		printf(GRN"\n- Parsing Succesful -\n\n"WHT);
	return (0);
}