/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:17:31 by daechoi           #+#    #+#             */
/*   Updated: 2021/12/13 20:57:08 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_printf(const char *str, ...)
{
	int 	i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (str[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (str[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else
				return (0);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (i);
}

int main()
{
	char *i = "dsfdsa";
	int j = 1020;
	char k = 'A';
	ft_printf(" %s %d %c ", i, j, k);
}
