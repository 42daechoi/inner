/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:15 by daechoi           #+#    #+#             */
/*   Updated: 2022/05/03 16:57:52 by daechoi          ###   ########.fr       */
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
    close(fd);
}

void    check_map_compare(char c, t_gameset gameset, char compare)
{
    if (c != compare)
        ft_printerr("map error\n");
}

int	check_object(t_gameset gameset)
{
	int	i;
	int	exit_cnt;
	int	position_cnt;
	int	collectible_cnt;

	i = 0;
	exit_cnt = 0;
	position_cnt = 0;
	collectible_cnt = 0;
	while (i < ft_strlen(gameset.map_line))
	{
		if (gameset.map_line[i] == 'P')
			position_cnt++;
		else if (gameset.map_line[i] == 'C')
			collectible_cnt++;
		else if (gameset.map_line[i] == 'E')
			exit_cnt++;
		i++;
	}
	if (exit_cnt == 0)
		ft_printerr("exit err\n");
	if (position_cnt != 1)
		ft_printerr("position err\n");
	if (collectible_cnt == 0)
		ft_printerr("collectible err\n");
    return (collectible_cnt);
}

void    check_map(t_gameset *gameset)
{
    int i;

    i = 0;
    while (i < ft_strlen(gameset->map_line))
    {
        if (i < gameset->map_width)
            check_map_compare(gameset->map_line[i], *gameset, '1');
        else if (i % (gameset->map_width + 1) == 0)
            check_map_compare(gameset->map_line[i], *gameset, '1');
        else if (i / gameset->map_height == gameset->map_width - 1)
            check_map_compare(gameset->map_line[i], *gameset, '1');
		else if (i > ft_strlen(gameset->map_line) - gameset->map_width)
			check_map_compare(gameset->map_line[i], *gameset, '1');
        else if (i % (gameset->map_width + 1) == gameset->map_width)
        {
            check_map_compare(gameset->map_line[i], *gameset, '\n');
			check_map_compare(gameset->map_line[i - 1], *gameset, '1');
        }
        i++;
    }
	if (i % (gameset->map_width + 1) != gameset->map_width)
		check_map_compare(gameset->map_line[i], *gameset, '\n');
	gameset->coll_max = check_object(*gameset);
}