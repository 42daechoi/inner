/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:34:07 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/06 18:13:15 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char    *spec_flags(t_info info, int *print_len, char sign)
{
    if (info.sharp && info.type == 'x')
    {
		(*print_len) += 2;
		return ("0x");
    }
    else if (info.sharp && info.type == 'X')
    {
		(*print_len) += 2;
		return ("0X");
    }
    else if (sign != '-' && info.space && (info.type == 'd' || info.type == 'i'))
    {
		(*print_len)++;
		return (" ");
    }
    else if (sign != '-' && info.plus)
    {
		(*print_len)++;
		return ("+");
    }
    else return (NULL);
}

int pointer_format(unsigned long n, t_info info)
{
    int     print_len;
    char    *pad_str;
    char    *s;

    print_len = 0;
    if (n == 0 || info.prec > -1)
        s = ft_strdup("0");
    else
        s = ft_malloc_nbr_base(n, "0123456789abcdef");
    if (!s)
        return (-1);
    print_len = ft_strlen(s);
    pad_str = padding(info.zero, info.width - print_len - 2);
    if (!pad_str)
        return (-1);
    if (info.minus > 0)
    {
        ft_putstr_fd("0x", 1);
        ft_putstr_fd(s, 1);
        ft_putstr_fd(pad_str, 1);
    }
    else
    {
        ft_putstr_fd(pad_str, 1);
        ft_putstr_fd("0x", 1);
        ft_putstr_fd(s, 1);
    }
    print_len += ft_strlen(pad_str);
    print_len += 2;
    free(s);
    free(pad_str);
    return (print_len);
}

int unsignedint_format(unsigned int n, t_info info)
{
    char    *s;
    char    *pad_str;
    char    *zpad_str;
    int     print_len;

    print_len = 0;
    if (!n && info.prec == 0)
        s = ft_strdup("");
    else if (info.type == 'u')
        s = ft_itoa(n);
    else if (info.type == 'x')
        s = ft_malloc_nbr_base(n, "0123456789abcdef");
    else
        s = ft_malloc_nbr_base(n, "0123456789ABCDEF");
    zpad_str = set_zpad(info, s);
    if (!zpad_str)
        return (-1);
    if (info.prec > -1)
        info.zero = 0;
    if (info.prec < (int)ft_strlen(s))
        pad_str = padding(info.zero, info.width - ft_strlen(s));
    else
        pad_str = padding(info.zero, info.width - info.prec);
    if (!pad_str)
        return (-1);
    if (info.minus > 0)
    {
        if (n)
            ft_putstr_fd(spec_flags(info, &print_len, '+'), 1);
        ft_putstr_fd(zpad_str, 1);
        ft_putstr_fd(pad_str, 1);
    }
    else
    {
        ft_putstr_fd(pad_str, 1);
        if (n)
            ft_putstr_fd(spec_flags(info, &print_len, '+'), 1);
        ft_putstr_fd(zpad_str, 1);
    }
    print_len += ft_strlen(pad_str) + ft_strlen(zpad_str);
    free(s);
    free(pad_str);
    free(zpad_str);
    return (print_len);
}