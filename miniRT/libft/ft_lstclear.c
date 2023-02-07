/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:48:50 by kiyoon            #+#    #+#             */
/*   Updated: 2021/11/24 13:54:16 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*temp;

	if (!lst || !del)
		return ;
	cur = *lst;
	while (cur)
	{
		temp = cur->next;
		del(cur->content);
		free(cur);
		cur = temp;
	}
	*lst = NULL;
}
