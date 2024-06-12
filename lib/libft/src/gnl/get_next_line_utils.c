/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:17:33 by tfrily            #+#    #+#             */
/*   Updated: 2023/11/28 16:28:41 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr_gnl(char *s, int c, char **cfound)
{
	if (s == NULL)
	{
		*cfound = NULL;
		return (NULL);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			*cfound = (char *)s;
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		*cfound = (char *)s;
		return ((char *)s);
	}
	*cfound = NULL;
	return (NULL);
}

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

void	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*newchar;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen_gnl(s1);
	lens2 = ft_strlen_gnl(s2);
	if (lens1 == 0 && lens2 == 0)
		return (0);
	newchar = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (newchar == NULL)
		return (NULL);
	newchar[lens1 + lens2] = '\0';
	ft_memcpy(newchar, s1, lens1);
	ft_memcpy(&newchar[lens1], s2, lens2);
	free(s1);
	return (newchar);
}
