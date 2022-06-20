/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:33:46 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/20 16:40:09 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a)
{
    int	len;
	int	temp;

	len = ft_strlen(a);
	if (len < 2)
		return ;
	temp = a[len - 1];
	a[len - 1] = a[len - 2];
	a[len - 2] = temp;
}

void	sb(int *b)
{
    int	len;
	int	temp;

	len = ft_strlen(b);
	if (len < 2)
		return ;
	temp = b[len - 1];
	b[len - 1] = b[len - 2];
	b[len - 2] = temp;
}

void	ss(char *a, char *b)
{
	sa(a);
	sa(b);
}

void	pa(char **a, char *b)
{
	int		a_len;
	int		b_len;
	int		i;
	char	*temp;

	i = 0;
	a_len = ft_strlen(*a);
	b_len = ft_strlen(b);
	if (b_len < 1)
		return ;
	temp = *a;
	*a = malloc((a_len + 2) * sizeof(char));
	while (i < a_len-1)
	{
		*a[i] = temp[i];
		i++;
	}
	*a[i++] = b[b_len - 1];
	printf("%c", *a[i - 1]);
	*a[i] = '\0';
	printf("[%s]", *a);
	//free(temp);
}