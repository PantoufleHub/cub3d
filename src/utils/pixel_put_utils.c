/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:56:40 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 10:56:41 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x > 0 && x < WIDTH && y > 0 && y < HEIGHT))
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_blend(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x > 0 && x < WIDTH && y > 0 && y < HEIGHT))
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dst
		= blend_colors((int)(*dst), color, (1 - get_t(color) / 255.0));
}
