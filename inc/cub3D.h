#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include "render.h"

# define WIDTH (640)
# define HEIGHT (480)

typedef struct	s_img_data
{
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
}				t_img_data;


void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
#endif
