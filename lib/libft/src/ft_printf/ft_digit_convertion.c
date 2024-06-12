/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_convertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:32:49 by tfrily            #+#    #+#             */
/*   Updated: 2023/11/16 16:25:47 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d_i_convertion(int digit, int *count)
{
	long	divider;
	long	ln;
	size_t	res;

	ln = digit;
	if (ln < 0)
	{
		ft_putchar('-', count);
		ln *= -1;
	}
	divider = 1;
	while (divider * 10 <= ln)
		divider *= 10;
	while (divider)
	{
		res = ln / divider + '0';
		write(1, &res, 1);
		ln = ln % divider;
		divider = divider / 10;
		(*count)++;
	}
}

void	ft_u_convertion(unsigned int digit, int *count)
{
	unsigned long	divider;
	unsigned long	ln;
	size_t			res;

	ln = digit;
	divider = 1;
	while (divider * 10 <= ln)
		divider *= 10;
	while (divider)
	{
		res = ln / divider + '0';
		write(1, &res, 1);
		ln = ln % divider;
		divider = divider / 10;
		(*count)++;
	}
}

void	ft_digit_convertion(int digit, char c, int *count)
{
	if (c == 'd' || c == 'i')
		ft_d_i_convertion(digit, count);
	else if (c == 'u')
		ft_u_convertion((unsigned)digit, count);
	else if (c == 'x')
		ft_convert_hex((unsigned)digit, count, "0123456789abcdef");
	else if (c == 'X')
		ft_convert_hex((unsigned)digit, count, "0123456789ABCDEF");
}
