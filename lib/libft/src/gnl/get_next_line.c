/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:17:31 by tfrily            #+#    #+#             */
/*   Updated: 2023/11/29 10:31:31 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *s, char *c_found)
{
	char		*line;
	size_t		lens;
	size_t		len_c_found;

	if (s == 0)
		return (0);
	if (*s == '\0')
		return (NULL);
	lens = ft_strlen_gnl(s);
	len_c_found = ft_strlen_gnl(c_found);
	line = malloc((lens - len_c_found + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[lens - len_c_found + 1] = '\0';
	ft_memcpy(line, s, lens - len_c_found + 1);
	if (c_found != NULL)
		line[lens - len_c_found] = '\n';
	free (s);
	return (line);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*memory;
	size_t	str_len;

	str_len = ft_strlen_gnl(s1);
	memory = malloc((str_len + 1));
	if (memory == NULL)
		return (memory = NULL);
	ft_memcpy(memory, s1, str_len + 1);
	return (memory);
}

int	static_calloc(char **stash, int fd)
{
	int	x;

	x = 0;
	if (stash[fd] == 0)
	{
		stash[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (stash[fd] == NULL)
			return (0);
		while (x < BUFFER_SIZE + 1)
		{
			stash[fd][x] = 0;
			x++;
		}
	}
	return (1);
}

size_t	ft_read_line(char **stash, char **c_found, char **line, int fd)
{
	size_t	read_bytes;

	read_bytes = -1;
	if (ft_strchr_gnl(stash[fd], '\n', c_found) == NULL)
		*line = ft_strjoin_gnl(*line, stash[fd]);
	while ((ft_strchr_gnl(stash[fd], '\n', c_found)) == NULL)
	{
		read_bytes = read(fd, stash[fd], BUFFER_SIZE);
		stash[fd][read_bytes] = 0;
		if (!read_bytes)
			break ;
		if (*c_found == NULL)
			*line = ft_strjoin_gnl(*line, stash[fd]);
		else
			stash[fd] = 0;
	}
	if (read_bytes == 0 || read_bytes == (size_t)-1)
		*line = ft_strjoin_gnl(*line, stash[fd]);
	*line = extract_line(*line, *c_found);
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD_LIMIT];
	char		*c_found;
	char		*line;
	size_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!static_calloc(stash, fd))
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = 0;
		return (NULL);
	}
	line = 0;
	read_bytes = ft_read_line(stash, &c_found, &line, fd);
	if (read_bytes == 0 || c_found == NULL)
	{
		free(stash[fd]);
		stash[fd] = 0;
	}
	if (c_found != NULL)
		ft_memcpy(stash[fd], c_found + 1, ft_strlen_gnl(c_found + 1) + 1);
	return (line);
}
