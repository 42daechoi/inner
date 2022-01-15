/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:30:37 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/16 05:40:15 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*padding(int zero_flag, int pad_len)
{
	char	*pad_str;
	int		i;

	i = 0;
	if (pad_len < 0)
		return (ft_strdup(""));
	pad_str = (char *)malloc((pad_len + 1) * sizeof(char));
	if (!pad_str)
		return (NULL);
	if (zero_flag == 1)
	{
		while (i < pad_len)
			pad_str[i++] = '0';
	}
	else
	{
		while (i < pad_len)
			pad_str[i++] = ' ';
	}
	pad_str[i] = '\0';
	return (pad_str);
}

int	char_format(char c, t_info info)
{
	char	*pad_str;
	int		print_len;

	pad_str = padding(info.zero, info.width - 1);
	if (!pad_str)
		return (-1);
	if (info.minus > 0)
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(pad_str, 1);
	}
	else
	{
		ft_putstr_fd(pad_str, 1);
		ft_putchar_fd(c, 1);
	}
	print_len = ft_strlen(pad_str) + 1;
	free(pad_str);
	return (print_len);
}

int	str_format(char *s, t_info info)
{
	char	*pad_str;
	int		print_len;
	char	*str;

	print_len = 0;
	if (!s)
		s = "(null)";
	if (info.prec > -1)
		str = ft_substr(s, 0, info.prec);
	else
		str = ft_strdup(s);
	if (!str)
		return (-1);
	pad_str = print_strformat(str, info);
	if (!pad_str)
		return (-1);
	print_len = ft_strlen(pad_str) + ft_strlen(str);
	free_va(2, str, pad_str);
	return (print_len);
}

char	*set_zpad(t_info info, char *itoa_str)
{
	char	*zpad_str;

	if (!itoa_str)
		return (NULL);
	if (info.prec > 0 && itoa_str[0] != '-')
		zpad_str = padding(1, info.prec - ft_strlen(itoa_str));
	else if (info.prec > 0 && itoa_str[0] == '-' )
		zpad_str = padding(1, info.prec - ft_strlen(itoa_str) + 1);
	else
		zpad_str = ft_strdup("");
	if (!zpad_str)
		return (NULL);
	zpad_str = sort_zpad(itoa_str, zpad_str);
	if (!zpad_str)
		return (NULL);
	return (zpad_str);
}

int	int_format(int n, t_info info)
{
	char	*zpad_str;
	char	*pad_str;
	char	*itoa_str;
	int		print_len;

	print_len = 0;
	itoa_str = set_itoa_str(info, n);
	zpad_str = set_zpad(info, itoa_str);
	if (info.prec > -1)
		info.zero = 0;
	pad_str = set_pad_str(itoa_str, info);
	if (!itoa_str || !zpad_str || !pad_str)
		return (-1);
	if (info.zero > 0 && info.width > (int)ft_strlen(itoa_str) && zpad_str[0] == '-')
	{
		zpad_str[0] = '0';
		pad_str[0] = '-';
	}
	if (info.minus > 0)
		putstr_va(3, spec_flags(info, &print_len, itoa_str[0], 0), zpad_str, pad_str);
	else
		putstr_va(3, pad_str, spec_flags(info, &print_len, itoa_str[0], 0), zpad_str);
	print_len += ft_strlen(pad_str) + ft_strlen(zpad_str);
	free_va(3, itoa_str, pad_str, zpad_str);
	return (print_len);
}
