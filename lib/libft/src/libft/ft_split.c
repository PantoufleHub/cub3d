/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:23:44 by tfrily            #+#    #+#             */
/*   Updated: 2024/01/23 18:22:02 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_elements(char const *str, char sep)
{
	size_t	count;
	size_t	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (sep != *str && x == 0)
		{
			x = 1;
			count++;
		}
		else if (sep == *str)
			x = 0;
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	nbr;
	size_t	i;
	size_t	j;
	size_t	k;
	char	**arraystr;

	i = 0;
	j = 0;
	k = 0;
	nbr = nbr_elements(s, c);
	arraystr = (char **)ft_calloc(nbr + 1, sizeof(char *));
	if (!s || arraystr == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
			arraystr[k++] = ft_substr(s, j, i - j);
	}
	arraystr[k] = NULL;
	return (arraystr);
}
