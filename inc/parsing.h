#ifndef PARSING_H
# define PARSING_H

typedef struct s_img_data
{
	int		width;
	int		height;
	void	*img;
	char	*path;
}	t_img_data;

typedef struct s_map_data
{
	void		*mlx;
	void		*win;
	int			**map;
	int			player_data[4]; // Xpos, Ypos, Xrot, Yrot
	int			floor_color;
	int			ceiling_color;
	t_img_data	*n_img_data;
	t_img_data	*e_img_data;
	t_img_data	*s_img_data;
	t_img_data	*w_img_data;
}	t_map_data;

int					parse(char *path, t_map_data *data);

void				init_map_data(t_map_data *data);

#endif