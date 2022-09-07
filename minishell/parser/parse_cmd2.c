/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:29:41 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 20:44:30 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	join_arr(t_token *t, int j, int i, char **arr)
{
	int		k;
	char	*temp;
	int		l;

	k = -1;
	l = 0;
	if (l == 0)
	{
		ft_free(t[j].option[i]);
		t[j].option[i] = ft_strdup("");
	}
	while (arr[++k])
	{
		if (l > 0)
		{
			temp = t[j].option[i];
			t[j].option[i] = ft_strjoin(temp, " ");
			free(temp);
		}
		temp = t[j].option[i];
		t[j].option[i] = ft_strjoin(temp, arr[k]);
		ft_free(temp);
		ft_free(arr[k]);
	}
	ft_free(arr);
}

void	skipspace(t_token *t, t_lenpos *lp)
{
	while (t[lp->j].str[++lp->i] == ' ' && t[lp->j].str[lp->i])
		;
	while (t[lp->j].str[lp->i++] != ' ' && t[lp->j].str[lp->i])
		;
}

void	get_lenpos(t_token *t, t_lenpos *lp)
{
	while (t[lp->j].str[++lp->i])
	{
		lp->len = 0;
		lp->pos = 0;
		if (t[lp->j].str[lp->i] == '<' || t[lp->j].str[lp->i] == '>' \
			|| !ft_strncmp(&(t[lp->j].str[lp->i]), "<<", 2) \
			|| !ft_strncmp(&(t[lp->j].str[lp->i]), ">>", 2))
		{
			if (!ft_strncmp(&(t[lp->j].str[lp->i]), "<<", 2) \
				|| !ft_strncmp(&(t[lp->j].str[lp->i]), ">>", 2))
				lp->i++;
			skipspace(t, lp);
			if (t[lp->j].str[lp->i] != '<' \
				&& t[lp->j].str[lp->i] != '>' && t[lp->j].str[lp->i])
			{
				lp->pos = lp->i;
				while (t[lp->j].str[lp->i++] && t[lp->j].str[lp->i] != '<'\
					&& t[lp->j].str[lp->i] != '>')
					lp->len++;
				break ;
			}
			lp->i--;
		}
	}
}

int	is_special(char *str)
{
	if (!ft_strncmp(str, "$", 1))
		return (1);
	else if (!ft_strncmp(str, "~", 2))
		return (1);
	return (0);
}

char	*join_lastdollar(char *str, char *en_rv)
{
	char	*temp;

	if (str[ft_strlen(str) - 1] == '$')
	{
		temp = en_rv;
		en_rv = ft_strjoin(temp, "$");
		ft_free(temp);
	}
	return (en_rv);
}
