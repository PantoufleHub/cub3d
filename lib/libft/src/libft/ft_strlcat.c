/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:08:36 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/16 18:08:41 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_index;
	size_t	src_index;
	size_t	src_length;

	dst_index = 0;
	src_index = 0;
	src_length = ft_strlen(src);
	while (dst[dst_index] && dst_index < dstsize)
		dst_index++;
	if (dst_index == dstsize)
		return (dst_index + src_length);
	while (src[src_index] && dst_index + src_index + 1 < dstsize)
	{
		dst[dst_index + src_index] = src[src_index];
		src_index++;
	}
	if (dst_index + src_index < dstsize)
		dst[dst_index + src_index] = '\0';
	return (dst_index + src_length);
}
