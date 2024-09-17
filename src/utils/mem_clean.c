/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:27:10 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/17 16:27:32 by tfrily           ###   ########.fr       */
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
