/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:27:10 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/18 14:36:57 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	clean_textures(t_texture_data textures[4], t_data *data)
{
	int	index;

	index = 0;
	if (!textures)
		return ;
	while (index < 4)
	{
		if (textures[index].img_data->img)
			mlx_destroy_image(data->mlx, textures[index].img_data->img);
		if (textures[index].path)
			ft_clean(textures[index].path);
		free(textures[index].img_data);
		index++;
	}
}

void	mem_clean(t_data *data)
{
	ft_clean2dtable(data->map);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	clean_textures(data->textures, data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
