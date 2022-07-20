/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:20:43 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/19 20:44:34 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_aqinfo(t_aqinfo *aqinfo, int start, int end)
{
	aqinfo->pivot = start;
	aqinfo->i = aqinfo->pivot + 1;
	aqinfo->j = end;
}

void	arr_swap(int *arr, t_aqinfo *aq)
{
	if (aq->i > aq->j)
	{
		aq->temp = arr[aq->j];
		arr[aq->j] = arr[aq->pivot];
		arr[aq->pivot] = aq->temp;
	}
	else
	{
		aq->temp = arr[aq->i];
		arr[aq->i] = arr[aq->j];
		arr[aq->j] = aq->temp;
	}
}

void	arr_quick_sort(int *arr, int start, int end)
{
	t_aqinfo	aq;

	init_aqinfo(&aq, start, end);
	if (start >= end)
		return ;
	while (aq.i <= aq.j)
	{
		while (aq.i <= end && arr[aq.i] <= arr[aq.pivot])
			aq.i++;
		while (aq.j > start && arr[aq.j] >= arr[aq.pivot])
			aq.j--;
		arr_swap(arr, &aq);
	}
	arr_quick_sort(arr, start, aq.j - 1);
	arr_quick_sort(arr, aq.j + 1, end);
}

void	get_pivot(t_info *info, t_stack *stack, int s_size)
{
	int		*arr;
	int		i;
	t_stack	*temp;

	if (ft_stacksize(stack) < 4)
		return ;
	temp = stack;
	i = 0;
	arr = (int *)malloc(s_size * sizeof(int));
	if (!arr)
		ft_printerr("Error\n");
	while (i < s_size)
	{
		arr[i] = get_prev(stack, i)->data;
		i++;
	}
	arr_quick_sort(arr, 0, --i);
	info->pivot_s = arr[(int)(s_size / 3)];
	info->pivot_b = arr[2 * (int)(s_size / 3)];
	free(arr);
}
