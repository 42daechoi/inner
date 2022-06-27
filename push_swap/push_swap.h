/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:20:52 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/27 20:37:01 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
    int             data;
    struct s_stack  *next;
} t_stack;

t_stack	*ft_newstack(int data);
void	ft_push(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
int	    ft_stacksize(t_stack *lst);
int	    ft_pop(t_stack *stack);
void	cal_swap(t_stack *stack);
void	cal_push(t_stack *receiver, t_stack *giver);
void	cal_rotate(t_stack *stack);
void	cal_rev_rotate(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
void    sort(t_stack *a, t_stack *b);

#endif