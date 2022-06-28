/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:30:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/28 23:32:57 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	int		temp;

	if (ac < 2)
		exit(1);
	temp = ft_atoi(av[--ac]);
	a = ft_newstack(temp);
	while (ac > 1)
	{
		temp = ft_atoi(av[--ac]);
		ft_push(&a, ft_newstack(temp));
	}
	int i = 0;
	b = ft_newstack(i++);
	while (i < 3)
	{
		ft_push(&b, ft_newstack(i++));
	}
	//cal_swap(a);
	//cal_push(a, b);
	//cal_rotate(a);
	int	pivot;
	
	pivot = ft_stacklast(a)->data;
	sort(a, b, pivot);
	printf("bottom\n");
	while (a != NULL)
	{
		printf("a : %d\n", a->data);
		a = a->next;
	}
	printf("top\n");
	while (b != NULL)
	{
		printf("b : %d\n", b->data);
		b = b->next;
	}
}