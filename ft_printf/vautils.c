/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vautils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:51:05 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/16 05:41:18 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	putstr_va(int n, ...)
{
	va_list	ap;
	int		i;
	char	*str;

	va_start(ap, n);
	i = 0;
	while (i < n)
	{
		str = va_arg(ap, char *);
		ft_putstr_fd(str, 1);
		i++;
	}
	va_end(ap);
}

void	free_va(int n, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, n);
	i = 0;
	while (i < n)
	{
		free(va_arg(ap, char *));
		i++;
	}
	va_end(ap);
}
