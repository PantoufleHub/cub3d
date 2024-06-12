/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:04:32 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/16 10:17:12 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	int		x;

	cdst = (char *) dst;
	csrc = (char *) src;
	x = (int)len;
	if (cdst > csrc)
	{
		while (x > 0)
		{
			cdst[x - 1] = csrc[x - 1];
			x--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
