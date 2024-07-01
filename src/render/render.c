#include "../../inc/cub3D.h"

void	render(t_data data, t_vectors vectors)
{
	t_calc_info calc_infos;
	int side;
	double wall_dist;
	t_line line;
	int color;
	
	while(data.x < WIDTH)
	{
		calc_infos = get_calc_info(data.x, vectors.dir, vectors.plane, vectors.pos);
		side = dda(&calc_infos, data);
		wall_dist = get_wall_dist(side, calc_infos);
		line = get_line_height(wall_dist);
		if(data.map[calc_infos.mapX][calc_infos.mapY] == 1)
			color = create_trgb(0, 255, 0, 0);
		if(side == 1) 
			color = color / 2;
		pixel_put_line(data.img, data.x, line,color);
		data.x++;
	} 
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.mlx_win, data.img.img, 0, 0);
}


// IN -> t_img_data, t_vector
// OUT -> void 
//
