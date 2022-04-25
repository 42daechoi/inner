/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/04/26 00:37:35 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

#include <stdio.h>

#define X_EVENT_KEYPRESS		2
#define X_EVENT_KEYRELEASE		3

#define KEYCODE_W   			13
#define KEYCODE_A   			0
#define KEYCODE_S   			1
#define KEYCODE_D   			2
#define KEYCODE_ESC				53

typedef	struct s_gameset
{
	int		x;
	int		y;
	int		map_width;
	int		map_height;
	char	*map_line;
} t_gameset;

void	read_map(char *file, t_gameset *gameset);
void	image_rendering(void *mlx, void *win, t_gameset gameset);
void	ft_printerr(char *s);
void    check_map(t_gameset gameset);

#endif