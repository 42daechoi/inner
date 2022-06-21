/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:30:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/21 19:55:18 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list	*stack;
	t_list	*head;
	int		temp;

	if (ac < 2)
		exit(1);
	head = stack;
	temp = ft_atoi(av[--ac]);
	stack = ft_lstnew(&temp);
	printf("[%d]\n", temp);
	while (ac > 1)
	{
		temp = ft_atoi(av[--ac]);
		printf("[%d]\n", temp);
		ft_lstadd_back(&stack, ft_lstnew(&temp));
	}
	//sa(stack);
	while (stack != NULL)
	{
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
}