/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:27:10 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/18 14:36:57 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_keyrelease(int key, t_data *data)
{
	if (key == K_W)
		data->keyboard.up = 0;
	if (key == K_S)
		data->keyboard.down = 0;
	if (key == K_D)
		data->keyboard.right = 0;
	if (key == K_A)
		data->keyboard.left = 0;
	if (key == R_ARROW)
		data->keyboard.rot_right = 0;
	if (key == L_ARROW)
		data->keyboard.rot_left = 0;
	return (0);
}

int	ft_keypress(int key, t_data *data)
{
	if (key == K_W)
		data->keyboard.up = 1;
	if (key == K_S)
		data->keyboard.down = 1;
	if (key == K_D)
		data->keyboard.right = 1;
	if (key == K_A)
		data->keyboard.left = 1;
	if (key == R_ARROW)
		data->keyboard.rot_right = 1;
	if (key == L_ARROW)
		data->keyboard.rot_left = 1;
	if (key == K_ESC)
		on_destroy(data);
	return (0);
}

int	on_destroy(t_data *data)
{
	printf(RED"Game closed"WHT"\n");
	mem_clean(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	move(t_data *data)
{
	double	move_speed;
	double	rot_speed;

	move_speed = data->time.frame_time * 6.0;
	rot_speed = data->time.frame_time * 2.0;
	if (data->keyboard.left)
		right(data, move_speed);
	if (data->keyboard.right)
		left(data, move_speed);
	if (data->keyboard.up)
		forward(data, move_speed);
	if (data->keyboard.down)
		backward(data, move_speed);
	if (data->keyboard.rot_left)
		rotations(data, -rot_speed);
	if (data->keyboard.rot_right)
		rotations(data, rot_speed);
	return (0);
}

int	ft_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, on_destroy, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_hook(data->win, E_KEYPRESS, 1L << 0, ft_keypress, data);
	mlx_hook(data->win, E_KEYRELEASE, 1L << 1, ft_keyrelease, data);
	return (0);
}
