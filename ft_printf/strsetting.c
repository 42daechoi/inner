/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsetting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:52:43 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/16 05:05:46 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*print_strformat(char *str, t_info info)
{
	char	*pad_str;
	
	if (info.width > 0)
		pad_str = padding(info.zero, info.width - ft_strlen(str));
	else
		pad_str = ft_strdup("");
	if (!pad_str)
		return (NULL);
	if (info.minus > 0)
		ft_putstr_va(2, str, pad_str);
	else
		ft_putstr_va(2, pad_str, str);
	return (pad_str);
}

char	*sort_zpad(char *abs, char *zpad_str)
{
	char	*temp;

	if (abs[0] == '-')
	{
		temp = zpad_str;
		zpad_str = ft_strjoin(temp, abs + 1);
		free(temp);
		if (!zpad_str)
			return (NULL);
		temp = zpad_str;
		zpad_str = ft_strjoin("-", temp);
		free(temp);
		if (!zpad_str)
			return (NULL);
	}
	else
	{
		temp = zpad_str;
		zpad_str = ft_strjoin(temp, abs);
		free(temp);
		if (!zpad_str)
			return (NULL);
	}
	return (zpad_str);
}

char	*set_itoa_str(t_info info, int n)
{
	char	*itoa_str;

	if (!n && info.prec == -1)
		itoa_str = ft_strdup("0");
	else if (!n && info.prec == 0)
		itoa_str = ft_strdup("");
	else
		itoa_str = ft_itoa(n);
	return (itoa_str);
}

char	*set_pad_str(char *itoa_str, t_info info)
{
	char	*pad_str;

	if(!itoa_str)
		return (NULL);
	if (info.prec < (int)ft_strlen(itoa_str))
		pad_str = padding(info.zero, info.width - ft_strlen(itoa_str));
	else
	{
		if (itoa_str[0] == '-')
			pad_str = padding(info.zero, info.width - info.prec - 1);
		else
			pad_str = padding(info.zero, info.width - info.prec);
	}
	return (pad_str);
}

char	*set_s(unsigned int n, t_info info)
{
	char	*s;

	if (!n && info.prec == 0)
		s = ft_strdup("");
	else if (info.type == 'u')
		s = ft_itoa(n);
	else if (info.type == 'x')
		s = ft_malloc_nbr_base(n, "0123456789abcdef");
	else
		s = ft_malloc_nbr_base(n, "0123456789ABCDEF");
	return (s);
}