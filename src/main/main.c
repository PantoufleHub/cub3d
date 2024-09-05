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
		printf(GRN"\n- Parsing Succesful -\n"CYN"Have fun!"WHT"\n");
	ft_hooks(&data);
	render(&data);
	mlx_hook(data.win, 17, 0, on_destroy, NULL);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
