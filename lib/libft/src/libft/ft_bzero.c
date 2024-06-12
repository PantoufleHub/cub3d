/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:34:27 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/12 16:53:05 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			index;	
	unsigned char	*str;

	index = 0;
	str = (unsigned char *) s;
	while (index < n && n > 0)
	{
		str[index] = '\0';
		index++;
	}
}
