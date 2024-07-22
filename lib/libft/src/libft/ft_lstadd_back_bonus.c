/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:21:08 by tfrily            #+#    #+#             */
/*   Updated: 2023/12/08 15:56:27 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*t_last;

	if (!lst || !new_list)
		return ;
	if (!*lst)
	{
		*lst = new_list;
		return ;
	}
	t_last = ft_lstlast(*lst);
	t_last->next = new_list;
}
