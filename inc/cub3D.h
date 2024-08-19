#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
#include "render.h"
#include <sys/time.h>

// # define WIDTH (640)
// # define HEIGHT (480)

# define WIDTH (1920)
# define HEIGHT (1080)
# define SPEED (0.5)
# define ROTSPEED (0.2)
# define TRUE (1)
# define FALSE (0)

enum e_key
{
	K_W  = 119,
	K_A  = 97,
	K_S  = 115,
	K_D  = 100,
	K_ESC = 65307
};

enum e_events
{
	E_KEYPRESS = 2
};

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

typedef struct	s_time
{
	struct	timeval	ref_time;
	float	FrameTime;
	float	time;
	float	oldTime;
}				t_time;

typedef struct	s_data
{
	t_img_data		img;
	int				x;
	char			**map;
	t_mlx			mlx;
	t_time			time;
	t_calc_info		calc_info;
	t_vectors		vec;
}				t_data;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	pixel_put_line(t_img_data img, int x, t_line vertical_line, int color);
int		create_trgb(int t, int r, int g, int b);
int		render(t_data *data);
int		dda(t_calc_info *calc_info, t_data *data);
int		ft_hooks(t_data *data);
long	get_time_elapse(struct timeval ref_time_of_day);
void	rotations(t_data *data, double rotspeed);
struct timeval	init_timer(void);
int wallside(t_data *data, int side);
#endif
