/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:59:25 by tfrily            #+#    #+#             */
/*   Updated: 2023/10/19 17:59:27 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	to_trim(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	char	*newstr;

	if (!s1)
		return (0);
	i = 0;
	end = ft_strlen(s1);
	while (i < end && to_trim(set, s1[i]))
		i++;
	while (end > i && to_trim(set, s1[end - 1]))
		end--;
	newstr = malloc(sizeof(char) * (end - i + 1));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, s1 + i, (end - i + 1));
	return (newstr);
}
