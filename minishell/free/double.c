/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:11:09 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/23 23:11:44 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_infile(t_token *token, int index)
{
	int	i;

	i = 0;
	if (!token[index].infile)
		return ;
	if (token[index].infile[0])
	{
		while (token[index].infile[i])
		{
			free(token[index].infile[i]);
			token[index].infile[i++] = NULL;
		}
	}
	free(token[index].infile);
	token[index].infile = NULL;
}

void	free_outfile(t_token *token, int index)
{
	int	i;

	i = 0;
	if (!token[index].outfile)
		return ;
	if (token[index].outfile[0])
	{
		while (token[index].outfile[i])
		{
			free(token[index].outfile[i]);
			token[index].outfile[i++] = NULL;
		}	
	}
	free(token[index].outfile);
	token[index].outfile = NULL;
}

void	free_arr(t_token *token, int index)
{
	int	i;

	i = 0;
	if (!token[index].arr)
		return ;
	if (token[index].arr[0])
	{
		while (token[index].arr[i])
		{
			free(token[index].arr[i]);
			token[index].arr[i++] = NULL;
		}
	}
	free(token[index].arr);
	token[index].arr = NULL;
}

void	free_option(t_token *token, int index)
{
	int	i;

	i = 0;
	if (!token[index].option[0])
	{
		free(token[index].option);
		return ;
	}
	while (token[index].option[i])
	{
		free(token[index].option[i]);
		token[index].option[i++] = NULL;
	}
	free(token[index].option);
	token[index].option = NULL;
}

void	free_here_doc(t_token *token, int index)
{
	int	i;

	i = 0;
	if (!token[index].here_doc)
		return ;
	if (token[index].here_doc[0])
	{
		while (token[index].here_doc[i])
		{
			free(token[index].here_doc[i]);
			token[index].here_doc[i++] = NULL;
		}
	}
	free(token[index].here_doc);
	token[index].here_doc = NULL;
}
