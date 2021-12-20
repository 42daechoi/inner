/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:22:22 by daechoi           #+#    #+#             */
/*   Updated: 2021/12/20 20:21:53 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int	    ft_isdigit(int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);

typedef struct s_info
{
    int     minus;
    int     zero;
    int     width;
    int     prec;
    char    type;
}   t_info;


#endif