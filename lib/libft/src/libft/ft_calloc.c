/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:00:27 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/13 17:22:38 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = 0;
	memory = malloc(size * count);
	if (memory == NULL)
		return (memory = NULL);
	ft_memset(memory, 0, size * count);
	return (memory);
}
