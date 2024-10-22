/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:28:00 by tfrily            #+#    #+#             */
/*   Updated: 2024/09/18 11:00:23 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free an element.
 *
 * @param ptr The element to free
 * @return int 0
 */
int	ft_clean(char *ptr)
{
	if (ptr == NULL)
		return (0);
	free(ptr);
	ptr = NULL;
	return (0);
}
