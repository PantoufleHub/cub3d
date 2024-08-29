#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include "constants.h"
# include "error_msg.h"
# include "colors.h"
# include "colors.h"

// # define WIDTH (640)
// # define HEIGHT (480)

enum e_key
{
	K_W  = 13,
	K_A  = 0,
	K_S  = 1,
	K_D  = 2,
	K_ESC = 53
};

// NOTE: FOR LINUX
// enum e_key
// {
// 	K_W  = 119,
// 	K_A  = 97,
// 	K_S  = 115,
// 	K_D  = 100,
// 	K_ESC = 65307
// };

enum e_events
{
	E_KEYPRESS = 2
};

typedef struct	s_vector
{
	double x;
	double y;
}				t_vector;

typedef struct	s_vectors
{
	t_vector plane;
	t_vector pos;
	t_vector dir;

}				t_vectors;

typedef struct	s_calc_info
{
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	rayDirX;
	double	rayDirY;
	int		stepX;
	int		stepY;
}				t_calc_info;


typedef struct	s_line
{
	int	drawStart;
	int	drawEnd;
}		t_line;

typedef struct	s_img_data
{
	void	*img;
	void	*addr;
	int	bit_per_pixel;
	int	size_line;
	int	endian;
}		t_img_data;

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

typedef struct s_texture_data
{
	int		width;
	int		height;
	void	*img;
	char	*path;
}	t_texture_data;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img_data	img;
	int		x;
	char	**map;
	t_time	time;
	t_calc_info	calc_info;
	t_vectors	vec;
	int		floor_color;
	int		ceiling_color;
	t_texture_data	textures[4]; // N E S W
}		t_data;

// PARSING
int					parse(char *path, t_data *data);

void				init_map_data(t_texture_data *data);


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
t_calc_info	get_calc_info(int x, t_vector dir, t_vector plane, t_vector pos);
// void		dda(t_calc_info *calc_info, int **map); // TODO: get back to this version after TEST
double get_wall_dist(int side, t_calc_info calc_info);
t_line get_line_height(double wall_dist);
int	init_data(t_data *data);
#endif
