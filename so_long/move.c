/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:36:32 by daechoi           #+#    #+#             */
/*   Updated: 2022/05/09 15:42:09 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	end_game(t_gameset g)
{
	ft_putnbr_fd(g.move_cnt, 1);
	write(1, "steps. Misson Complete.", 6);
	exit(0);
}

void	move_w(t_gameset *g)
{
	int	i;

	i = -1;
	while (g->map_line[++i] != 'P');
	if (g->map_line[i + g->map_width + 1] == 'C')
		g->coll_cnt++;
	if (g->map_line[i + g->map_width + 1] == 'E' && g->coll_cnt == g->coll_max)
	{
		g->move_cnt++;
		end_game(*g);
	}
	else if (g->map_line[i + g->map_width + 1] != '1' && g->map_line[i + g->map_width + 1] != 'E')
	{
		g->map_line[i] = 0;
		g->map_line[i + g->map_width + 1] = 'P';
		g->move_cnt++;
		ft_putnbr_fd(g->move_cnt, 1);
		write(1, "steps.", 6);
		image_rendering(*g);
	}
}

void	move_s(t_gameset *g)
{
	int	i;

	i = -1;
	while (g->map_line[++i] != 'P');
	if (g->map_line[i + g->map_width + 1] == 'C')
		g->coll_cnt++;
	if (g->map_line[i + g->map_width + 1] == 'E' && g->coll_cnt == g->coll_max)
	{
		g->move_cnt++;
		end_game(*g);
	}
	else if (g->map_line[i + g->map_width + 1] != '1' && g->map_line[i + g->map_width + 1] != 'E')
	{
		g->map_line[i] = 0;
		g->map_line[i + g->map_width + 1] = 'P';
		g->move_cnt++;
		ft_putnbr_fd(g->move_cnt, 1);
		write(1, "steps.", 6);
		image_rendering(*g);
	}
}

void	move_a(t_gameset *g)
{
	int	i;

	i = -1;
	while (g->map_line[++i] != 'P');
	if (g->map_line[i - 1] == 'C')
		g->coll_cnt++;
	if (g->map_line[i - 1] == 'E' && g->coll_cnt == g->coll_max)
	{
		g->move_cnt++;
		end_game(*g);
	}
	else if (g->map_line[i - 1] != '1' && g->map_line[i - 1] != 'E')
	{
		g->map_line[i] = 0;
		g->map_line[i - 1] = 'P';
		g->move_cnt++;
		ft_putnbr_fd(g->move_cnt, 1);
		write(1, "steps.", 6);
		image_rendering(*g);
	}
}

void	move_d(t_gameset *g)
{
	int	i;

	i = -1;
	while (g->map_line[++i] != 'P');
	if (g->map_line[i + 1] == 'C')
		g->coll_cnt++;
	if (g->map_line[i + 1] == 'E' && g->coll_cnt == g->coll_max)
	{
		g->move_cnt++;
		end_game(*g);
	}
	else if (g->map_line[i + 1] != '1' && g->map_line[i + 1] != 'E')
	{
		g->map_line[i] = 0;
		g->map_line[i + 1] = 'P';
		g->move_cnt++;
		ft_putnbr_fd(g->move_cnt, 1);
		write(1, "steps.", 6);
		image_rendering(*g);
	}
}