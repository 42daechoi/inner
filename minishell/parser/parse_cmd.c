/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:10:24 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 21:35:37 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parse_enrv(char **envp, char *str)
{
	char	*en_rv;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (str[ft_strlen(str) - 1] == '$')
		{
			if (!ft_strncmp(envp[i], str, ft_strlen(str) - 1))
				break ;
		}
		else
			if (ft_strnstr(envp[i], str, ft_strlen(str)) == envp[i])
				break ;
	}
	if (envp[i])
	{
		if (str[ft_strlen(str) - 1] == '$')
			en_rv = ft_strdup(&(envp[i][ft_strlen(str)]));
		else
			en_rv = ft_strdup(&(envp[i][ft_strlen(str) + 1]));
	}
	else
		en_rv = ft_strdup("");
	return (en_rv);
}

char	*get_enrv(char **envp, char *str)
{
	char	*en_rv;

	if (!ft_strncmp(str, "$", 2))
		return (str);
	else if (!ft_strncmp(str, "$?", 3) || !ft_strncmp(str, "?", 2))
	{
		ft_free(str);
		return (ft_itoa(g_status));
	}
	else if (!ft_strncmp(str, "~", 2))
	{
		ft_free(str);
		str = ft_strdup("HOME");
	}
	else if (!ft_strncmp(str, "\"", 1))
		return (str);
	else if (!ft_strncmp(str, "\'", 1))
		return (str);
	en_rv = parse_enrv(envp, str);
	en_rv = join_lastdollar(str, en_rv);
	ft_free(str);
	return (en_rv);
}

void	parse_option(t_token *token, int j, char **envp)
{
	int		i;
	int		k;
	char	**arr;

	if (!token[j].cmd)
	{
		token[j].option = malloc(sizeof(char *) * 2);
		token[j].option[0] = ft_strdup("");
		token[j].option[1] = NULL;
		return ;
	}
	token[j].option = withoutq_split(token[j].cmd, ' ');
	i = -1;
	while (token[j].option[++i])
	{
		arr = dollar_split(token[j].option[i], '$');
		k = 0;
		if (is_special(token[j].option[i]))
			arr[0] = get_enrv(envp, arr[0]);
		while (arr[++k])
			arr[k] = get_enrv(envp, arr[k]);
		join_arr(token, j, i, arr);
		doubleq_parse(token, j, i, envp);
		delete_quotes(token, j, i);
	}
}

char	**splitnjoin(t_token *token, int j, char *sep)
{
	char	**arr;
	char	*temp;

	arr = withoutq_split(token[j].str, sep[0]);
	temp = get_jointemp(arr);
	arr = withoutq_split(temp, sep[1]);
	ft_free(temp);
	temp = get_jointemp(arr);
	arr = withoutq_split(temp, sep[2]);
	ft_free(temp);
	return (arr);
}

void	parse_cmd(t_token *token, int token_cnt, char **envp)
{
	t_lenpos	lp;
	char		**arr;

	lp.j = -1;
	while (++lp.j < token_cnt)
	{
		lp.i = -1;
		token[lp.j].cmd = ft_strdup("");
		arr = splitnjoin(token, lp.j, "<> ");
		while (arr[++lp.i])
		{
			if (!is_exist(token, arr[lp.i], lp))
				strjoin_withs(token, lp, arr[lp.i]);
			ft_free(arr[lp.i]);
		}
		ft_free(arr);
		parse_option(token, lp.j, envp);
	}
}
