/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:44:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/18 23:23:57 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_token(t_token *t, int token_cnt)
{
	int	i;

	i = 0;
	while (i < token_cnt)
	{
		t[i].arr = NULL;
		t[i].infile = NULL;
		t[i].outfile = NULL;
		t[i].cmd = NULL;
		t[i].here_doc = NULL;
		t[i].last_doc = NULL;
		t[i].append_flag = NULL;
		t[i].option = NULL;
		t[i].fd[0] = -1;
		t[i].fd[1] = -1;
		t[i].append_flag = NULL;
		t[i].option = NULL;
		i++;
	}
}

void	init_pipesplit(t_pipesplit *p)
{
	p->inquotes = 0;
	p->inword = 0;
	p->issep = 0;
	p->cnt = 0;
	p->i = -1;
}
