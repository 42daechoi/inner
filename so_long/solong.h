/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/05/17 15:22:20 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

# define X_EVENT_KEYPRESS		2
# define X_EVENT_DESTROYNOTIFY	17

# define KEYCODE_W   			13
# define KEYCODE_A   			0
# define KEYCODE_S   			1
# define KEYCODE_D   			2
# define KEYCODE_ESC			53

typedef struct s_gameset
{
	int		map_width;
	int		map_height;
	char	*map_line;
	int		move_cnt;
	int		coll_cnt;
	int		coll_max;
	void	*mlx;
	void	*win;
}	t_gameset;

typedef struct s_imgset
{
	void	*wall;
	void	*tile;
	void	*coll;
	void	*exit;
	void	*player;
}	t_imgset;

void	read_map(char *file, t_gameset *gameset);
void	image_rendering(t_gameset gameset);
void	ft_printerr(char *s);
void	check_map(t_gameset *gameset);
void	move_s(t_gameset *g);
void	move_d(t_gameset *g);
void	move_w(t_gameset *g);
void	move_a(t_gameset *g);
void	ft_putnbr_fd(int n, int fd);

#endif