/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:22:59 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/16 15:23:01 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	str_len;

	str_len = ft_strlen(src);
	x = 0;
	if (dstsize == 0)
	{
		return (str_len);
	}
	while (x < dstsize - 1 && src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	if (dstsize > 0)
	{
		dst[x] = '\0';
	}
	return (str_len);
}
