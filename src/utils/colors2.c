#include "../inc/cub3D.h"

int	blend_colors(int color1, int color2, float alpha)
{
	int	r;
	int	g;
	int	b;

	r = (int)((alpha * get_r(color2)) + ((1 - alpha) * get_r(color1)));
	g = (int)((alpha * get_g(color2)) + ((1 - alpha) * get_g(color1)));
	b = (int)((alpha * get_b(color2)) + ((1 - alpha) * get_b(color1)));
	return (create_trgb(0, r, g, b));
}