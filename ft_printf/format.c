/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:30:37 by daechoi           #+#    #+#             */
/*   Updated: 2021/12/20 20:25:22 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char    *padding(int zero_flag, int pad_len)
{
    char    *pad_str;
    int     i;

    i = 0;
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

    if (info.width > 0)
        pad_str = padding(info.zero, info.width - 1);
    else
        pad_str = ft_strdup("");
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
    free(pad_str);
    return (info.width);
}

int str_format(char *s, t_info info)
{
    char    *pad_str;
    char    *temp;

    if (!s)
        return (-1);
    if (info.width > 0)
        pad_str = padding(info.zero, info.width - ft_strlen(s));
    else
        pad_str = ft_strdup("");
    if (!pad_str)
        return (-1);
    temp = pad_str;
    if (info.minus > 0)
    {
        pad_str = ft_strjoin(s, temp);
        free(temp);
        if (!pad_str)
            return (-1);
        ft_putstr_fd(pad_str, 1);
    }
    else
    {
        pad_str = ft_strjoin(temp, s);
        free(temp);
        if (!pad_str)
            return (-1);
        ft_putstr_fd(pad_str, 1);
    }
    free(pad_str);
    return (info.width);
}