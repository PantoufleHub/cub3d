/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean2dtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:29:06 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/06 14:26:52 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free all the element of a 2d array.
 *
 * @param ptr The 2d table
 * @return int 0
 */
int	ft_clean2dtable(char **ptr)
{
	int	x;

	x = 0;
	while (ptr[x])
	{
		free (ptr[x]);
		ptr[x] = NULL;
		x++;
	}
	free (ptr);
	ptr = NULL;
	return (0);
}