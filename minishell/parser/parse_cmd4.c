/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:33:56 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 21:36:05 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dq_join(t_token *token, int i, int j)
{
	char	*temp;

	temp = token[j].option[i];
	token[j].option[i] = ft_strjoin(temp, "\"");
	free(temp);
}

void	free2(void *s1, void *s2)
{
	ft_free(s1);
	ft_free(s2);
}

void	dq_p2(char **arr, char **envp)
{
	char	**arr2;
	char	*temp;
	int		l;
	int		k;

	l = -1;
	while (arr[++l])
	{
		arr2 = dollar_split(arr[l], '$');
		k = 0;
		if (is_special(arr[l]))
			arr2[0] = get_enrv(envp, arr2[0]);
		while (arr2[++k])
			arr2[k] = get_enrv(envp, arr2[k]);
		free(arr[l]);
		arr[l] = ft_strdup("");
		k = -1;
		while (arr2[++k])
		{
			temp = arr[l];
			arr[l] = ft_strjoin(temp, arr2[k]);
			free2(temp, arr2[k]);
		}
		free(arr2);
	}
}

void	doubleq_parse(t_token *t, int j, int i, char **envp)
{
	char	**arr;
	char	*temp;
	char	*temp2;
	int		l;

	arr = doubleq_split(t[j].option[i], '\"');
	dq_p2(arr, envp);
	temp2 = ft_strdup(t[j].option[i]);
	free(t[j].option[i]);
	t[j].option[i] = ft_strdup("");
	l = -1;
	while (arr[++l])
	{
		if (l > 0 || (l == 0 && temp2[0] == '\"' && temp2[1] != '\"'))
			dq_join(t, i, j);
		temp = t[j].option[i];
		t[j].option[i] = ft_strjoin(temp, arr[l]);
		free2(temp, arr[l]);
	}
	if (ft_strlen(temp2) >= 2 \
	&& t[j].option[i][ft_strlen(t[j].option[i]) - 1] != '\"' \
	&& temp2[ft_strlen(temp2) - 1] == '\"' \
	&& temp2[ft_strlen(temp2) - 2] != '\"')
		dq_join(t, i, j);
	free2(temp2, arr);
}
