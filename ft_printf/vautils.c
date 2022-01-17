/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vautils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:51:05 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/17 19:28:17 by daechoi          ###   ########.fr       */
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

int	check_spell(const char *str, va_list ap, t_info info)
{
	int	i;
	int	curr_len;
	int	print_len;

	i = -1;
	print_len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			parsing(str, &i, &info);
			curr_len = print_format(&ap, info);
			if (curr_len == -1)
				return (-1);
			print_len += curr_len;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			print_len++;
		}
		init_info(&info);
	}
	return (print_len);
}
