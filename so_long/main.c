/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:10 by daechoi           #+#    #+#             */
/*   Updated: 2022/04/21 17:25:45 by daechoi          ###   ########.fr       */
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
	void		*mlx_ptr;
	void		*win_ptr;

	if (argc != 2)
		ft_printerr("ERROR\n");
	read_map(argv[1], &gameset);
	check_map(gameset);
	mlx_ptr = mlx_init();
	param_init(&gameset);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	//image_rendering(mlx_ptr, win_ptr, gameset);
	mlx_hook(win_ptr, X_EVENT_KEYPRESS, 0, &press_key, &gameset);
	mlx_loop(mlx_ptr);
	return (0);
}