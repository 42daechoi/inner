/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:20:43 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/07 17:40:46 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void arr_quick_sort(int *data, int start, int end)
{
	int	pivot;
	int	i;
	int j;
	int temp;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
        while (i <= end && data[i] <= data[pivot])
			i++;
        while (j > start && data[j] >= data[pivot])
			j--;
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	arr_quick_sort(data, start, j - 1);
	arr_quick_sort(data, j + 1, end);
}

void	get_pivot(t_info *info, t_stack *stack)
{
	int		*arr;
	int		i;
	int		size;
	t_stack	*node;

	if (ft_stacksize(stack) < 4)
		return ;
	i = 0;
	node = stack;
	size = ft_stacksize(stack);
	arr = (int *)malloc(ft_stacksize(stack) * sizeof(int));
	if (!arr)
		ft_printerr("arr_sort error");
	while (node != NULL)
	{
		arr[i] = node->data;
		i++;
		node = node->next;
	}
	arr_quick_sort(arr, 0, --i);
	info->pivot_s = arr[(int)(size / 3)];
	info->pivot_b = arr[(int)(size / 3) * 2];
	free(arr);
}