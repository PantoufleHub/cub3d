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

static void	clean_textures(t_texture_data textures[4], t_data *data)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		mlx_destroy_image(data->mlx, textures[index].img_data->img);
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
}
