/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:58:28 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/20 16:35:48 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack, int s_size, int flag)
{
	int	i;

	i = 0;
	if (s_size < 2)
		return (true);
	if (flag == 0)
	{
		while (s_size > i)
		{
			if (get_prev(stack, i)->data > get_prev(stack, i + 1)->data)
				return (false);
			i++;
		}
	}
	else
	{
		while (s_size > i)
		{
			if (get_prev(stack, i)->data < get_prev(stack, i + 1)->data)
				return (false);
			i++;
		}
	}
	return (true);
}

void	reverse_in_sort(t_info *info, int ra_cnt, int rb_cnt)
{
	while (ra_cnt-- > 0 && rb_cnt-- != 0)
		rrr(info->a, info->b);
	while (ra_cnt-- > 0)
		rra(info->a);
	while (rb_cnt-- > 0)
		rrb(info->b);
}
