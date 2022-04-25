/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:10 by daechoi           #+#    #+#             */
/*   Updated: 2022/04/26 00:37:26 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	param_init(t_gameset *gameset)
{
	gameset->x = 0;
	gameset->y = 0;
}

int	press_key(int keycode, t_gameset *gameset)
{
	if (keycode == KEYCODE_A)
		gameset->y++;
	else if (keycode == KEYCODE_S)
		gameset->x--;
	else if (keycode == KEYCODE_D)
		gameset->y--;
	else if (keycode == KEYCODE_W)
		gameset->x++;
	else if (keycode == KEYCODE_ESC)
		exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	t_gameset	gameset;
	void		*mlx;
	void		*win;

	if (argc != 2)
		ft_printerr("ERROR\n");
	read_map(argv[1], &gameset);
	printf("%s\n", gameset.map_line);
	check_map(gameset);
	mlx_ptr = mlx_init();
	param_init(&gameset);
	win_ptr = mlx_new_window(mlx, gameset.map_width * 64, gameset.map_height * 64, "mlx 42");
	image_rendering(mlx, win, gameset);
	mlx_hook(win, X_EVENT_KEYPRESS, 0, &press_key, &gameset);
	mlx_loop(mlx);
	return (0);
}