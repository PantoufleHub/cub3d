/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:23:22 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/26 10:23:24 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_int_len(int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_int_min(void)
{
	char	*res;

	res = ft_calloc(12, sizeof(char));
	ft_strlcpy(res, "-2147483648", 12);
	return (res);
}

static void	ft_fill_chr(int n, char *mem, int sign, int len_int)
{
	size_t	unit;

	n *= sign;
	while (n != 0)
	{
		unit = n % 10;
		unit += '0';
		if (sign == -1)
			mem[len_int--] = unit;
		else
			mem[--len_int] = unit;
		n /= 10;
	}
	if (sign == -1)
		mem[0] = '-';
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*mem;
	int		len_int;

	len_int = ft_int_len(n);
	if (n == -2147483648)
		return (ft_int_min());
	if (n < 0 || n == 0)
		mem = ft_calloc(len_int + 2, sizeof(char));
	else
		mem = ft_calloc(len_int + 1, sizeof(char));
	if (mem == NULL)
		return (NULL);
	sign = 1;
	if (n == 0)
	{
		ft_strlcpy(mem, "0", 2);
		return (mem);
	}
	if (n < 0)
		sign = -1;
	ft_fill_chr(n, mem, sign, len_int);
	return (mem);
}
