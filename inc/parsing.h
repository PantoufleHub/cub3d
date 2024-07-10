#ifndef PARSING_H
# define PARSING_H

typedef struct s_map_data
{
	int		**map;
	int		player_data[4]; // Xpos, Ypos, Xrot, Yrot
	int		floor_color;
	int		ceiling_color;
	char	*NO_texture_path;
	char	*EA_texture_path;
	char	*SO_texture_path;
	char	*WE_texture_path;
}	t_map_data;

int 				parse(char *path, t_map_data *data);

void 				init_map_data(t_map_data *data);

#endif