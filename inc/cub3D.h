#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include "render.h"

// # define WIDTH (640)
// # define HEIGHT (480)

# define WIDTH (1920)
# define HEIGHT (1080)

typedef struct	s_img_data
{
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
}				t_img_data;

typedef struct	s_mlx 
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct	s_data
{
	t_img_data	img;
	int			x;
	char		**map;
	t_mlx		mlx;
}				t_data;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	pixel_put_line(t_img_data img, int x, t_line vertical_line, int color);
int		create_trgb(int t, int r, int g, int b);
void	render(t_data data, t_vectors vectors);
int		dda(t_calc_info *calc_info, t_data data);

#endif
