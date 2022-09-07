/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:21 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 19:28:29 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	shift_quotes(t_token *token, int j, int i, t_delqt *dq)
{
	while (dq->pos + 1 != dq->k)
	{
		token[j].option[i][dq->pos] = token[j].option[i][dq->pos + 1];
		dq->pos++;
	}
	while (token[j].option[i][dq->pos + 2])
	{
		token[j].option[i][dq->pos] = token[j].option[i][dq->pos + 2];
		dq->pos++;
	}
	token[j].option[i][dq->pos] = '\0';
	dq->k -= 2;
	return (1);
}

void	delete_quotes(t_token *token, int j, int i)
{
	t_delqt	dq;
	int		status;

	dq.onecnt = 0;
	dq.twocnt = 0;
	dq.k = -1;
	status = 0;
	while (token[j].option[i][++dq.k])
	{
		if (token[j].option[i][dq.k] == '\'' && dq.twocnt % 2 == 0)
		{
			dq.onecnt++;
			if (dq.onecnt % 2 == 0)
				shift_quotes(token, j, i, &dq);
			dq.pos = dq.k;
		}
		else if (token[j].option[i][dq.k] == '\"' && dq.onecnt % 2 == 0)
		{
			dq.twocnt++;
			if (dq.twocnt % 2 == 0)
				shift_quotes(token, j, i, &dq);
			dq.pos = dq.k;
		}
	}
}

int	is_exist(t_token *t, char *str, t_lenpos lp)
{
	int	j;

	j = -1;
	while (t[lp.j].infile && t[lp.j].infile[++j])
		if (!ft_strncmp(t[lp.j].infile[j], str, ft_strlen(str)))
			return (1);
	j = -1;
	while (t[lp.j].outfile && t[lp.j].outfile[++j])
		if (!ft_strncmp(t[lp.j].outfile[j], str, ft_strlen(str)))
			return (1);
	j = -1;
	while (t[lp.j].here_doc && t[lp.j].here_doc[++j])
		if (!ft_strncmp(t[lp.j].here_doc[j], str, ft_strlen(str)))
			return (1);
	return (0);
}

void	strjoin_withs(t_token *token, t_lenpos lp, char *str)
{
	char	*temp;

	if (lp.i > 0)
	{
		temp = token[lp.j].cmd;
		token[lp.j].cmd = ft_strjoin(temp, " ");
		ft_free(temp);
	}
	temp = token[lp.j].cmd;
	token[lp.j].cmd = ft_strjoin(temp, str);
	ft_free(temp);
}

char	*get_jointemp(char **arr)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = -1;
	temp2 = ft_strdup("");
	while (arr[++i])
	{
		if (i > 0)
		{
			temp = temp2;
			temp2 = ft_strjoin(temp, " ");
			ft_free(temp);
		}
		temp = temp2;
		temp2 = ft_strjoin(temp, arr[i]);
		ft_free(temp);
		ft_free(arr[i]);
	}
	ft_free(arr);
	return (temp2);
}
