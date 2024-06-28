#incldue "../../inc/cub3D.h"
render()
{
	int side;
	double wall_dist;
	t_line line;
	t_calc_info calc_infos;

	while(x < WIDTH)
	{

		calc_infos = get_calc_info(x, dir, plane, pos);
		side = dda(&calc_infos);
		wall_dist = get_wall_dist(side, calc_infos);
		line = get_line_height(wall_dist);

		//choose wall color
		int color = 0x00000000;

		if(map[calc_infos.mapX][calc_infos.mapY] == 1)
			color = create_trgb(0, 255, 0, 0);
		if(side == 1) 
			color = color / 2;
		pixel_put_line(img, x, line,color);
		x++;

	}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}


// IN -> t_img_data, t_vector
// OUT -> void 
