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

int pointer_format(long long n, t_info info)
{
    int     print_len;
    char    *pad_str;
    char    *s;

    print_len = 0;
    if (!n || info.prec > -1)
        return (-1);
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
    if (info.type == 'u')
        s = ft_itoa(n);
    else if (info.type == 'x')
        s = ft_malloc_nbr_base(n, "0123456789abcdef");
    else
        s = ft_malloc_nbr_base(n, "01223456789ABCDEF");
    zpad_str = set_zpad(info, s);
    if (!zpad_str)
        return (-1);
    pad_str = padding(info.zero, info.width - info.prec);
    if (!pad_str)
        return (-1);
    if (info.minus > 0)
    {
        ft_putstr_fd(zpad_str, 1);
        ft_putstr_fd(pad_str, 1);
    }
    else
    {
        ft_putstr_fd(pad_str, 1);
        ft_putstr_fd(zpad_str, 1);
    }
    print_len = ft_strlen(pad_str) + ft_strlen(zpad_str);
    printf("<%zu %zu>", ft_strlen(pad_str), ft_strlen(zpad_str));
    free(s);
    free(pad_str);
    free(zpad_str);
    return (print_len);
}