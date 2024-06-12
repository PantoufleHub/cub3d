/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:34:45 by tfrily            #+#    #+#             */
/*   Updated: 2023/11/17 10:34:46 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
void	ft_convert_hex(unsigned long dec, int *count, char hex_table[]);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_p_convertion(void *p, int *count);
void	ft_char_convertion(va_list args, char c, int *count);
void	ft_digit_convertion(int digit, char c, int *count);

#endif
