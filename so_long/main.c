/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:10 by daechoi           #+#    #+#             */
/*   Updated: 2022/05/14 21:59:21 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	exit_game(t_gameset *gameset)
{
	mlx_destroy_window(gameset->mlx, gameset->win);
	exit(0);
}

int	press_key(int keycode, t_gameset *gameset)
{
	if (keycode == KEYCODE_A)
		move_a(gameset);
	else if (keycode == KEYCODE_S)
		move_s(gameset);
	else if (keycode == KEYCODE_D)
		move_d(gameset);
	else if (keycode == KEYCODE_W)
		move_w(gameset);
	else if (keycode == KEYCODE_ESC)
		exit_game(gameset);
	return (0);
}

void	gameset_init(t_gameset *gameset)
{
	gameset->map_width = 0;
	gameset->map_height = 0;;
	gameset->map_line = NULL;
	gameset->move_cnt = 0;
	gameset->coll_cnt = 0;
	gameset->coll_max = 0;
	gameset->mlx = NULL;
	gameset->win = NULL;
}

int	map_extension_check(char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (s_len < 4)
		return (0);
	if (!(s[s_len - 1] == 'r' && s[s_len - 2] == 'e' && s[s_len - 3] == 'b' && s[s_len - 4] == '.'))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_gameset	gameset;

	if (argc != 2 || map_extension_check(argv[1]) == 0)
		ft_printerr("argument error\n");
	gameset_init(&gameset);
	read_map(argv[1], &gameset);
	check_map(&gameset);
	gameset.mlx = mlx_init();
	gameset.win = mlx_new_window(gameset.mlx, gameset.map_width * 64, gameset.map_height * 64, "so_long");
	image_rendering(gameset);
	mlx_hook(gameset.win, X_EVENT_KEYPRESS, 0, &press_key, &gameset);
	mlx_hook(gameset.win, X_EVENT_DESTROYNOTIFY, 0, &exit_game, &gameset);
	mlx_loop(gameset.mlx);
	return (0);
}