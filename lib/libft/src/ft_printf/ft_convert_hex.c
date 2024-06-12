/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:18 by tfrily            #+#    #+#             */
/*   Updated: 2023/11/13 15:29:20 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_hex(unsigned long dec, int *count, char hex_table[])
{
	char	res[17];
	int		remainder;
	int		index;

	index = 0;
	res[16] = '\0';
	if (dec == 0)
		ft_putchar(0 + '0', count);
	while (dec > 0)
	{
		remainder = dec % 16;
		res[index++] = hex_table[remainder];
		dec /= 16;
	}
	index -= 1;
	while (index >= 0)
		ft_putchar(res[index--], count);
}

void	ft_p_convertion(void *p, int *count)
{
	unsigned long		addr;

	addr = (unsigned long)p;
	ft_putstr("0x", count);
	ft_convert_hex(addr, count, "0123456789abcdef");
}
