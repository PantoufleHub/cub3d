/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:57:33 by aperron           #+#    #+#             */
/*   Updated: 2024/09/18 10:57:34 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

int	create_trgb(int t, int r, int g, int b);

int	get_t(int trgb);

int	get_r(int trgb);

int	get_g(int trgb);

int	get_b(int trgb);

#endif