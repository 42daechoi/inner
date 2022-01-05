/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:22:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/05 17:13:05 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_info
{
    int     minus;
    int     zero;
    int     width;
    int     prec;
    char    type;
}   t_info;

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int	    ft_isdigit(int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int     str_format(char *s, t_info info);
int     char_format(char c, t_info info);
int     int_format(int n, t_info info);
char	*ft_itoa(int n);

#endif