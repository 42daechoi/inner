/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:22:32 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/07 20:22:34 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	free_char(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

void	ft_exit(int a)
{
	ft_putstr_fd("Error\n", 1);
	exit(a);
}

int	split_num(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}

int	exit_game(t_set *set)
{
	mlx_destroy_window(set->mlx, set->win);
	exit(0);
}
