/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:35:04 by daechoi           #+#    #+#             */
/*   Updated: 2022/04/26 00:52:03 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	image_init(void *mlx, void *win, t_gameset gameset)
{
	int	h;
	int	w;

	h = 0;
	while (h < gameset.map_height)
	{
		w = 0;
		while (w < gameset.map_width)
		{
			if (gameset.map_line[h * gameset.map_width + w] == '1')
			{
				mlx_put_image_to_window(mlx, win, "./wall.xpm", w * 64, h * 64);
			}
			else if (gameset.map_line[h * gameset.map_width + w] == 'C')
			{
				mlx_put_image_to_window(mlx, win, "./collectible.xpm", w * 64, h * 64);
			}
			else if (gameset.map_line[h * gameset.map_width + w] == 'P')
			{
				mlx_put_image_to_window(mlx, win, "./player.xpm", w * 64, h * 64);
			}
			else if (gameset.map_line[h * gameset.map_width + w] == 'E')
			{
				mlx_put_image_to_window(mlx, win, "./exit.xpm", w * 64, h * 64);
			}
			else
			{
				mlx_put_image_to_window(mlx, win, "./tile.xpm", w * 64, h * 64);
			}
			w++;
		}
		h++;
	}
}

void	image_rendering(void *mlx, void *win, t_gameset gameset)
{
	int		i;
	void	*img;
	int 	img_size = 64;

	i = 0;
	while (i < ft_strlen(gameset.map_line))
	{
		if (gameset.map_line[i] == '1')
			img = mlx_xpm_file_to_image(mlx, "./wall.xpm", &img_size, &img_size);
		else if (gameset.map_line[i] == '0')
			img = mlx_xpm_file_to_image(mlx, "./tile.xpm", &img_size, &img_size);
	}
	img = mlx_xpm_file_to_image(mlx, "./tile.xpm", &img_size, &img_size);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
}