/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convertion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:54 by tfrily            #+#    #+#             */
/*   Updated: 2023/11/16 16:40:24 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	while (*s)
	{
		ft_putchar(*s, count);
		s++;
	}
}

void	ft_char_convertion(va_list args, char c, int *count)
{
	static char	null_pointer[] = "(null)";
	char		*chk_arg;

	if (c == 's')
	{
		chk_arg = va_arg(args, char *);
		if (chk_arg == NULL)
			ft_putstr(null_pointer, count);
		else
			ft_putstr(chk_arg, count);
	}
	else if (c == 'c')
	{
		ft_putchar(va_arg(args, int), count);
	}
}
