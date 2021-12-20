/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:17:31 by daechoi           #+#    #+#             */
/*   Updated: 2021/12/20 20:11:45 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = '0';
}

static void	set_w_or_p(t_info *info, char c)
{
	if (info->prec == -1)
		info->width = info->width * 10 + (c - '0');
	else
		info->prec = info->prec * 10 + (c - '0');
}

static int	parsing(const char *str, int *i, t_info *info)
{
	t_info	info;

	while (str[*i] || ft_strchr("cspdiuxX%", str[*i]))
	{
		if (str[*i] == '-')
			info->minus = 1;
		else if (str[*i] == '0')
			info->zero = 1;
		else if (str[*i] == '.')
			info->prec = 0;
		else if (ft_isdigit(str[*i]))
			set_w_or_p(info, str[*i]);
		if (info->minus == 1 && info->zero == 1)
			return (-1);
		(*i)++;
	}
	info->type = str[*i];
	if (!(info->type == 'd' || info->type == 'i' || info->type == 'x' || info->type == 'X' || info->type == 'u'))
		info->zero = 0;
	return (1);
}

static int	print_format(va_list ap, t_info info)
{
	if (info.type == 'c')
		return (char_format(va_arg(ap, int), info));
	else if (info.type == 's')
		return (str_format(va_arg(ap, char *), info));
	else if (info.type == 'p')
		return (pointer_format(va_arg(ap, long long), info));
	else if (info.type == 'd' || info.type == 'i')
		return (str_format(va_arg(ap, int), info));
	else if (info.type == 'u' || info.type == 'x' || info.type == 'X')
		return (unsignedint_format(va_arg(ap, int), info));
	else if (info.type == '%')
		return (char_format(info.type, info));
	else
		return (-1);
}

int ft_printf(const char *str, ...)
{
	int 	i;
	va_list	ap;
	t_info 	info;
	int		print_len;

	i = 0;
	va_start(ap, str);
	init_info(&info);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (parsing(str, &i, &info) > -1)
				print_len += print_format(ap, info);
			else
				return (-1);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			print_len++;
		}
		i++;
	}
	va_end(ap);
	return (print_len);
}
