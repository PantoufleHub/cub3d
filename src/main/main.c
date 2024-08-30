#include "../../inc/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf(RED"Error\nPlease input single .cub file\n"WHT),
			EXIT_FAILURE);
	if (init_data(&data) < 0)
		return (printf(RED"Error\nCouldn't initialize data\n"WHT),
			EXIT_FAILURE);
	if (parse(argv[1], &data) < 0)
		return (printf(RED"\n- Parsing failed -\n\n"WHT), EXIT_FAILURE);
	else
		printf(GRN"\n- Parsing Succesful -\n\n"WHT);
	printf("1\n");
	ft_hooks(&data);
	printf("2\n");
	render(&data);
	printf("3\n");
	mlx_loop(data.mlx);
	printf("4\n");
	return (EXIT_SUCCESS);
}
