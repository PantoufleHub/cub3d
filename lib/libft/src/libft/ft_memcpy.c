/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:12:04 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/12 18:52:54 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;
	char	*cdst;
	char	*csrc;

	x = 0;
	cdst = (char *) dst;
	csrc = (char *) src;
	while (x < n && (csrc != (void *)0 || cdst != (void *)0))
	{
		cdst[x] = csrc[x];
		x++;
	}
	return (dst);
}
