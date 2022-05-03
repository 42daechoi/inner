/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:10 by daechoi           #+#    #+#             */
/*   Updated: 2022/05/03 18:41:26 by daechoi          ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_gameset	gameset;

	if (argc != 2)
		ft_printerr("ERROR\n");
	read_map(argv[1], &gameset);
	printf("%s\n", gameset.map_line);
	check_map(&gameset);
	gameset.mlx = mlx_init();
	param_init(&gameset);
	gameset.win= mlx_new_window(gameset.mlx, gameset.map_width * 64, gameset.map_height * 64, "mlx 42");
	image_rendering(gameset);
	mlx_hook(gameset.win, X_EVENT_KEYPRESS, 0, &press_key, &gameset);
	mlx_loop(gameset.mlx);
	return (0);
}