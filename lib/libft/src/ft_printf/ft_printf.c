/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:17:38 by tfrily            #+#    #+#             */
/*   Updated: 2023/11/17 14:45:05 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_argument_parser(va_list args, const char *str, int *count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'p')
				ft_p_convertion(va_arg(args, void *), count);
			else if (*str == 's' || *str == 'c')
				ft_char_convertion(args, *str, count);
			else if (*str == 'd' || *str == 'i' || *str == 'u')
				ft_digit_convertion(va_arg(args, int), *str, count);
			else if (*str == 'x' || *str == 'X')
				ft_digit_convertion(va_arg(args, int), *str, count);
			else if (*str == '%')
				ft_putchar(*str, count);
		}
		else
			ft_putchar(*str, count);
		str++;
	}
}

int	ft_printf(const char *string, ...)
{
	int		*count;
	int		res;
	va_list	args;

	res = 0;
	count = &res;
	va_start(args, string);
	ft_argument_parser(args, string, count);
	va_end(args);
	return (res);
}
