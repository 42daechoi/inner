/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:53:36 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/30 16:09:20 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif