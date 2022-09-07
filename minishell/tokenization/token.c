/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:15:11 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 15:50:00 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*malloc_token(char *s, int *token_cnt)
{
	t_token	*token;
	char	**split;
	int		i;

	i = -1;
	split = withoutq_split(s, '|');
	while (split[++i])
		(*token_cnt)++;
	token = (t_token *)ft_malloc(sizeof(t_token) * (i + 1));
	token[i].str = NULL;
	while (--i >= 0)
	{
		token[i].str = ft_strdup(split[i]);
		free(split[i]);
	}
	free(split);
	return (token);
}
