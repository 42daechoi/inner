/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:49:47 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/24 19:03:40 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		 *lst = new;
		 return ;
	}
	tail = ft_lstlast(*lst);
	tail->next = new;
	new->next = NULL;
}
