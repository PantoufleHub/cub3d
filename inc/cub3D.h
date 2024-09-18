/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:57:24 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 15:09:05 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# ifdef __APPLE__

enum e_key
{
	K_W = 13,
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_ESC = 53,
	L_ARROW = 123,
	R_ARROW = 124
};
# endif

# ifdef __unix__

enum e_key
{
	K_W = 119,
	K_A = 97,
	K_S = 115,
	K_D = 100,
	K_ESC = 65307
};
# endif

enum e_events
{
	E_KEYPRESS = 2
};

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_vectors
{
	t_vector	plane;
	t_vector	pos;
	t_vector	dir;

}				t_vectors;

typedef struct s_calc_info
{
	int			map_x;
	int			map_y;
	double		s_dist_x;
	double		s_dist_y;
	double		d_dist_x;
	double		d_dist_y;
	double		perp_dist;
	double		ray_dir_x;
	double		ray_dir_y;
	int			step_x;
	int			step_y;
	double		wall_x;
	int			tex_x;
	int			wall_side;
}				t_calc_info;

typedef struct s_line
{
	int	draw_start;
	int	draw_end;
}		t_line;

typedef struct s_img_data
{
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
}		t_img_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_time
{
	struct timeval	ref_time;
	float			frame_time;
	float			time;
	float			old_time;
}				t_time;

typedef struct s_texture_data
{
	int			width;
	int			height;
	char		*path;
	t_img_data	*img_data;
}	t_texture_data;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img_data		img;
	int				x;
	char			**map;
	int				nb_rows;
	t_time			time;
	t_calc_info		calc_info;
	t_vectors		vec;
	int				floor_color;
	int				ceiling_color;
	t_texture_data	textures[4];
}		t_data;

// PARSING
int					parse(char *path, t_data *data);
void				init_map_data(t_texture_data *data);
void				init_texture_data(t_texture_data *data);
void				my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void				pixel_put_line(t_img_data img, int x, t_line vertical_line,
						int color);
int					create_trgb(int t, int r, int g, int b);
int					render(t_data *data);
int					dda(t_calc_info *calc_info, t_data *data);
int					ft_hooks(t_data *data);
long				get_time_elapse(struct timeval ref_time_of_day);
void				rotations(t_data *data, double rotspeed);
void				left(t_data *data, double move_speed);
void				right(t_data *data, double move_speed);
struct timeval		init_timer(void);
t_calc_info			get_calc_info(int x, t_vector dir, t_vector plane,
						t_vector pos);
double				get_wall_dist(int side, t_calc_info calc_info);
t_line				get_line_height(double wall_dist);
int					init_data(t_data *data);
void				set_wallside(t_data *data, int side);
int					on_destroy(t_data *data);
int					w_is_in_bound(t_data *data, double movespeed);
int					s_is_in_bound(t_data *data, double movespeed);
int					getChannel(int color, int shift);
int					combineChannels(int a, int r, int g, int b);
int					blend_colors(int color1, int color2, float alpha);
void				my_mlx_pixel_put_blend(t_img_data *data, int x, int y,
						int color);
void				draw_minimap(t_data *data);
int					set_texture_path(int line_nb, char *line, t_data *data,
						char *path);
int					open_texture_path(int line_nb, char *line, t_data *data,
						char *path);
int					get_texture_path(int line_nb, char *line, t_data *data);
int					interpret_line_var(int line_nb, char *line, t_data *data);
int					interpret_line(int line_nb, char *line, t_data *data,
						t_list **map);
int					set_data_path(char *line, char **ptr, char *path);
int					parse_file(int fd, t_data *data, t_list **map);
int					parse_path(char *path, int *fd);
int					set_map(t_list *map, t_data *data);
int					get_nb_rows(char **map);
int					actually_set_color(int line_nb, char *line, int *data_ptr,
						int rgb[3]);
int					set_data_color(int line_nb, char *line, int *data_ptr);
int					set_color(int line_nb, char *line, t_data *data);
void				save_spacelolhaha(int (*pouet)[3]);
int					get_color(int line_nb, char *line, t_data *data);
void				init_texture_data(t_texture_data *data);
int					file_data_filled(t_data *data, int include_map);
void				set_player_data(char c, int col, int row, t_data *data);
int					get_player_data(t_list *map, t_data *data);
void				get_adjacents(char *lines[3], char (*adjacents)[4],
						int index);
int					c_is_in(char c, char *c_arr);
int					str_contains_only(char *str, char *c_arr);
void				print_no_nl(char *line);
int					is_space(char c);
int					print_err(char *line, int line_nb, char *msg);
int					map_char_valid(char c, char adjacent[4]);
int					parse_map3(char *prev_l, char *line, char *next_l,
						int *status);
int					parse_map2(t_list *prev_line, t_list *curr_line,
						int *status);
int					parse_map(t_list **map);
int					map_char_valid(char c, char adjacent[4]);
int					parse_map3(char *prev_l, char *line, char *next_l,
						int *status);
int					parse_map2(t_list *prev_line, t_list *curr_line,
						int *status);
int					parse_map(t_list **map);
int					read_map(int line_nb, char *line, t_list **map);
int					c_in_str(char *str, char *c_arr);
void				mem_clean(t_data *data);
#endif
