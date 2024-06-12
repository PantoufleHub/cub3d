/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:37:22 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/18 17:37:24 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*memory;
	size_t	str_len;

	str_len = ft_strlen(s1);
	memory = malloc((str_len + 1));
	if (memory == NULL)
		return (memory = NULL);
	ft_strlcpy(memory, s1, str_len + 1);
	return (memory);
}
