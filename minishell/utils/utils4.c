/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:48:35 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 21:34:23 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**lastdjoin(char *str, char c)
{
	char	**arr;
	char	*temp;
	int		i;

	arr = withoutq_split(str, c);
	if (str[ft_strlen(str) - 1] == '$')
	{
		i = -1;
		while (arr[(++i) + 1])
			;
		temp = arr[i];
		arr[i] = ft_strjoin(temp, "$");
		ft_free(temp);
		temp = NULL;
	}
	return (arr);
}

char	**dollar_split(char *str, char c)
{
	char	**arr;

	if (!ft_strncmp(str, "$", 2))
	{
		arr = ft_malloc(sizeof(char *) * 2);
		arr[0] = ft_strdup("$");
		arr[1] = NULL;
	}
	else if (!ft_strncmp(str, "$?", 3))
	{
		arr = ft_malloc(sizeof(char *) * 2);
		arr[0] = ft_strdup("$?");
		arr[1] = NULL;
	}
	else
		arr = lastdjoin(str, c);
	return (arr);
}

int	is_spacepipe(char *str)
{
	int	i;
	int	pos;
	int	flag;

	i = -1;
	pos = -1;
	while (str[++i])
	{
		flag = find_pipe(str, &i, &pos);
		if (flag == 1)
			return (1);
		else if (flag == 0 || i >= (int)ft_strlen(str))
			return (0);
	}
	if (pos == -1)
		return (0);
	return (1);
}

int	check_qorp(char *str)
{
	int		i;
	int		twocnt;
	int		onecnt;
	char	*temp;

	i = -1;
	twocnt = 0;
	onecnt = 0;
	while (str[++i])
	{
		if (str[i] == '\"' && onecnt % 2 == 0)
			twocnt++;
		else if (str[i] == '\'' && twocnt % 2 == 0)
			onecnt++;
	}
	temp = ft_strtrim(str, " ");
	i = -1;
	if (twocnt % 2 != 0 || onecnt % 2 != 0 || temp[ft_strlen(temp) - 1] == '<' \
	|| temp[ft_strlen(temp) - 1] == '>' || temp[ft_strlen(temp) - 1] == '|')
	{
		ft_free(temp);
		return (1);
	}
	ft_free(temp);
	return (0);
}

int	check_syntax(char *str)
{
	if (!*str)
		return (0);
	if (is_spacepipe(str))
	{
		g_status = 258;
		printf("syntax error near unexpected token `|\'\n");
		add_history(str);
		ft_free(str);
		return (1);
	}
	if (check_qorp(str) || ft_strnstr(str, "$$", ft_strlen(str)))
	{
		g_status = 258;
		printf("syntax error\n");
		add_history(str);
		ft_free(str);
		return (1);
	}
	return (0);
}
