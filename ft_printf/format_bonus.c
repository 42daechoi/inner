/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:30:37 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/06 18:12:55 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char    *padding(int zero_flag, int pad_len)
{
    char    *pad_str;
    int     i;

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

int char_format(char c, t_info info)
{
    char    *pad_str;
	int		print_len;

    //if (info.width > 0)
    pad_str = padding(info.zero, info.width - 1);
    //else
    //    pad_str = ft_strdup("");
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

int str_format(char *s, t_info info)
{
    char    *pad_str;
	int		print_len;
    char    *str;

	print_len = 0;
    if (!s)
        s = "(null)";
    if (info.prec > -1)
		str = ft_substr(s, 0, info.prec);
    else
        str = ft_strdup(s);
    if (!str)
        return (-1);
    if (info.width > 0)
        pad_str = padding(info.zero, info.width - ft_strlen(str));
    else
        pad_str = ft_strdup("");
    if (!pad_str)
        return (-1);
    if (info.minus > 0)
    {
        ft_putstr_fd(str, 1);
        ft_putstr_fd(pad_str, 1);
    }
    else
    {
        ft_putstr_fd(pad_str, 1);
        ft_putstr_fd(str, 1);
    }
	print_len = ft_strlen(pad_str) + ft_strlen(str);
    free(str);
    free(pad_str);
    return (print_len);
}

char	*set_zpad(t_info info, char *abs)
{
	char	*zpad_str;
    char    *temp;

	if (info.prec > 0 && abs[0] != '-')
        zpad_str = padding(1, info.prec - ft_strlen(abs));
    else if (info.prec > 0 && abs[0] == '-' )
        zpad_str = padding(1, info.prec - ft_strlen(abs) + 1);
    else
		zpad_str = ft_strdup("");
        if (!zpad_str)
            return (NULL);
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

int int_format(int n, t_info info)
{
    char    *zpad_str;
	char	*pad_str;
	char	*abs;
	int		print_len;
	
    if (!n && info.prec == -1)
        abs = ft_strdup("0");
    else if (!n && info.prec == 0)
		abs = ft_strdup("");
    else
	    abs = ft_itoa(n);
    print_len = 0;
	zpad_str = set_zpad(info, abs);
	if (info.prec > -1)
		info.zero = 0;
	if (!zpad_str)
		return (-1);
    if (info.prec < (int)ft_strlen(abs))
        pad_str = padding(info.zero, info.width - ft_strlen(abs));
    else
    {
        if (abs[0] == '-')
            pad_str = padding(info.zero, info.width - info.prec - 1);
        else
            pad_str = padding(info.zero, info.width - info.prec);
    }
    if (!pad_str)
	    return (-1);
    if (info.zero > 0 && info.width > (int)ft_strlen(abs) && zpad_str[0] == '-')
    {
        zpad_str[0] = '0';
        pad_str[0] = '-';
    }
    if (info.minus > 0)
    {
		ft_putstr_fd(spec_flags(info, &print_len, abs[0]), 1);
        ft_putstr_fd(zpad_str, 1);
        ft_putstr_fd(pad_str, 1);
    }
    else
    {
        ft_putstr_fd(pad_str, 1);
        ft_putstr_fd(spec_flags(info, &print_len, abs[0]), 1);
        ft_putstr_fd(zpad_str, 1);
    }
    print_len += ft_strlen(pad_str) + ft_strlen(zpad_str);
	free(abs);
    free(pad_str);
    free(zpad_str);
	return (print_len);
}