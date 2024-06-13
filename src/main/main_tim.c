#include "../../inc/cub3D.h"

int main()
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,1920 ,1080 , "SALUT ALEXIS");
	mlx_loop(mlx);
	printf("%p",mlx_win);
	return (0);
}
