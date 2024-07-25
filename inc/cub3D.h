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
# define SPEED (0.5)
# define ROTSPEED (5.0)
# define FOV (60)
# define TRUE (1)
# define RAYCAST_PRES (64)
# define FALSE (0)

// NOTE: FOR LINUX
// enum e_key
// {
// 	K_W  = 119,
// 	K_A  = 97,
// 	K_S  = 115,
// 	K_D  = 100,
// 	K_ESC = 65307
// };

// NOTE: FOR MAC OS
enum e_key
{
	K_W  = 13,
	K_A  = 0,
	K_S  = 1,
	K_D  = 2,
	K_ESC = 53
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

typedef struct	s_screen
{
	double	halfWidth;
	double	halfHeight;
}				t_screen;

typedef struct	s_render
{
	double distance;
}				t_render;

typedef struct	s_raycast
{
	double incrAngle;
	int	presicion;
}				t_raycast;


typedef struct	s_speed
{
	double movement;
	double rotation;
}				t_speed;

typedef struct	s_player
{
	double fov;
	double halfFov;
	double	x;
	double	y;
	double playerCos;
	double playerSin;
	double newX;
	double newY;
	double angle;
	t_speed speed;

}				t_player;

typedef struct	s_ray
{
	double x;
	double y;
	double rayCos;
	double raySin;
	double rayAngle;
}				t_ray;

typedef struct	s_data
{
	t_screen	screen;
	t_render	render;
	t_raycast	raycast;
	t_player	player;
	t_ray		ray;
	t_img_data	img;
	int			x;
	char		**map;
	t_mlx		mlx;
	t_vectors	vec;
}				t_data;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	pixel_put_line(t_img_data img, int x, t_line vertical_line, int color);
int		create_trgb(int t, int r, int g, int b);
void	refresh(t_data *data);
// int		dda(t_calc_info *calc_info, t_data *data);
int		ft_controls(t_data *data);
void	clear_screen(t_data *data);
double degreetoRadiant(double degree);
double	raycasting(t_data *data);
double cos_degree(double degree);
double sin_degree(double degree);
#endif
