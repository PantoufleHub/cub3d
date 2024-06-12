/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:20:58 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/19 16:21:00 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newchar;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (ft_strdup(""));
	newchar = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (newchar == NULL)
		return (newchar = NULL);
	ft_memcpy (newchar, s1, len_s1);
	ft_memcpy (&newchar[len_s1], s2, len_s2);
	return (newchar);
}
