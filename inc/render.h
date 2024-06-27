#ifndef RENDER_H
# define RENDER_H

typedef struct	s_vector
{
	double x;
	double y;

}				t_vector;

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

t_calc_info	get_calc_info(int x, t_vector dir, t_vector plane, t_vector pos);
// void		dda(t_calc_info *calc_info, int **map); // TODO: get back to this version after TEST
int		dda(t_calc_info *calc_info);

double get_wall_dist(int side, t_calc_info calc_info);
t_line get_line_height(double wall_dist);
#endif
