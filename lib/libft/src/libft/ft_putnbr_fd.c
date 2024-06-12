/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:17:10 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/26 13:17:14 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t		res;
	long long	divider;
	long long	ln;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	divider = 1;
	while (divider * 10 <= ln)
		divider *= 10;
	while (divider)
	{
		res = ln / divider + '0';
		write(fd, &res, 1);
		ln = ln % divider;
		divider = divider / 10;
	}
}
