/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:35:37 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/19 21:45:03 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_next_min(t_stack *s, t_var *v)
{
	while (v->i >= 0)
	{
		if (v->var < get_prev(s, v->i)->data \
			&& v->next_min > get_prev(s, v->i)->data)
			v->next_min = get_prev(s, v->i)->data;
		v->i--;
	}
	v->var = v->next_min;
}

int	find_min_max(t_stack *s, int flag, int s_size)
{
	t_var	v;

	v.i = 0;
	if (flag == 0)
		v.var = INT_MAX;
	else if (flag == 2)
	{
		v.var = INT_MAX;
		v.next_min = INT_MAX;
	}
	else
		v.var = INT_MIN;
	while (s_size > 0)
	{
		if (v.var > get_prev(s, v.i)->data && (flag == 0 || flag == 2))
			v.var = get_prev(s, v.i)->data;
		if (v.var < get_prev(s, v.i)->data && flag == 1)
			v.var = get_prev(s, v.i)->data;
		v.i++;
		s_size--;
	}
	if (flag == 2)
		get_next_min(s, &v);
	return (v.var);
}
