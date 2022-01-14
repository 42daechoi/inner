/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:17:31 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/06 18:20:30 by daechoi          ###   ########.fr       */
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
	info->sharp = 0;
	info->plus = 0;
	info->space = 0;
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
	while (str[*i] && !ft_strchr("cspdiuxX%", str[*i]))
	{
		if (str[*i] == '-')
			info->minus = 1;
		else if (str[*i] == '0' && info->width == 0 && \
					info->prec == -1 && info->minus == 0)
			info->zero = 1;
		else if (str[*i] == '.')
			info->prec = 0;
		else if (str[*i] == '#')
			info->sharp = 1;
		else if (str[*i] == '+')
			info->plus = 1;
		else if (str[*i] == ' ')
			info->space = 1;
		if (ft_isdigit(str[*i]))
			set_w_or_p(info, str[*i]);
		(*i)++;
	}
	info->type = str[*i];
	if (!(info->type == 'd' || info->type == 'i' || info->type == 'x' || info->type == 'X' || info->type == 'u'))
		info->zero = 0;
	if (info->minus == 1 && info->zero == 1)
			return (-1);
	return (1);
}

static int	print_format(va_list *ap, t_info info)
{
	if (info.type == 'c')
		return (char_format(va_arg(*ap, int), info));
	else if (info.type == 's')
		return (str_format(va_arg(*ap, char *), info));
	else if (info.type == 'p')
	 	return (pointer_format(va_arg(*ap, long long), info));
	else if (info.type == 'd' || info.type == 'i')
		return (int_format(va_arg(*ap, int), info));
	else if (info.type == 'u' || info.type == 'x' || info.type == 'X')
		return (unsignedint_format(va_arg(*ap, int), info));
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
	int		curr_len;

	print_len = 0;
	i = 0;
	va_start(ap, str);
	init_info(&info);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (parsing(str, &i, &info) > -1)
			{
				curr_len = print_format(&ap, info);
				if (curr_len == -1)
					return (-1);
				print_len += curr_len;
			}
			else
				return (-1);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			print_len++;
		}
		i++;
		init_info(&info);
	}
	va_end(ap);
	return (print_len);
}