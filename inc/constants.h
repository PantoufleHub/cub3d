/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:57:27 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 10:57:28 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define BLK "\033[30m"
# define RED "\033[31m"
# define GRN "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYN "\033[36m"
# define WHT "\033[37m"

# define WINDOW_TITLE "Kubtrwadé"

# define WIDTH (1920)
# define HEIGHT (1080)
# define MOVESPEED (6.0)
# define ROTSPEED (2.0)
# define TRUE (1)
# define FALSE (0)

// Only pair values for now
# define MAP_COLS 20
# define MAP_ROWS 20
//
# define MAP_TILE_SIZE 20
# define MAP_X 30
# define MAP_Y 30
# define MAP_WALL_COLOR 0xd44250
# define MAP_EMPTY_COLOR 0xe8e8e8
# define MAP_VOID_COLOR 0x5271ff
# define MAP_BORDER_COLOR 0x3D3D3D
# define MAP_TRANSPARENCY 0x2F000000

# define VEC_INIT (-2)

#endif