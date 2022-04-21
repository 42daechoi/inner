/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:15 by daechoi           #+#    #+#             */
/*   Updated: 2022/04/21 18:03:46 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    read_map(char *file, t_gameset *gameset)
{
    int     fd;
    char    *line;
    char    *temp;

    fd = open(file, O_RDONLY);
    if (fd <= 0)
        ft_printerr("file open error\n");
    line = get_next_line(fd);
    gameset->map_height = 0;
    gameset->map_width = ft_strlen(line) - 1;
    gameset->map_line = line;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {
            temp = gameset->map_line;
            gameset->map_line = ft_strjoin(temp, line);
            free(temp);
            free(line);
        }
        gameset->map_height++;
    }
	temp = gameset->map_line;
	gameset->map_line = ft_strjoin(temp, "\n");
	free(temp);
    close(fd);
}

void    check_map_wall(char c, t_gameset gameset)
{
    if (c != '1')
        ft_printerr("map wall error\n");
}

void    check_map(t_gameset gameset)
{
    int i;

    i = 0;
	printf("%s", gameset.map_line);
    while (i < ft_strlen(gameset.map_line))
    {
        if (i % (gameset.map_width + 1) == gameset.map_width)
        {
            if (gameset.map_line[i] == '\n')
            {
                check_map_wall(gameset.map_line[i - 1], gameset);
                i++;
                continue ;
            }
            else
            {
                ft_printerr("map length error\n");
                //맵길이 딱 2배 에러일 때 처리 필요
                continue ;
            }
        }
        if (i < gameset.map_width)
            check_map_wall(gameset.map_line[i], gameset);
        else if (i % (gameset.map_width + 1) == 0)
            check_map_wall(gameset.map_line[i], gameset);
        else if (i / gameset.map_height == gameset.map_width - 1)
            check_map_wall(gameset.map_line[i], gameset);
        i++;
    }
	if (i % (gameset.map_width + 1) != 0)
		ft_printerr("map length error\n");
}

void	image_rendering(void *mlx_ptr, void *win_ptr, t_gameset gameset)
{
	void	*img;
	int 	img_size = 64;

	img = mlx_xpm_file_to_image(mlx_ptr, "./tile.xpm", &img_size, &img_size);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
}

//길이 에러 첫 마지막 1 부족할때 처리