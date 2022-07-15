/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:03:15 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/15 16:46:09 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_count_prev(t_stack *s, int prev_count)
{
	int	i;
	t_stack *temp;

	i = 1;
	temp = s;
	while (ft_stacksize(s) - prev_count > i)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}