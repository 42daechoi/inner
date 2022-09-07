/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:06:59 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/24 16:36:11 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_child(t_token *token, t_heredoc *hd, int *any_heredoc)
{
	while (1)
	{
		hd->str = readline("> ");
		if (!hd->str)
			break ;
		if (!ft_strncmp(hd->str, hd->here_doc, ft_strlen(hd->here_doc)))
		{
			close(hd->fd);
			if (token[hd->j].last_doc == NULL)
				unlink(hd->filename);
			*any_heredoc = 0;
			if (!*any_heredoc)
				break ;
		}
		write(hd->fd, hd->str, ft_strlen(hd->str));
		write(hd->fd, "\n", 1);
		ft_free(hd->str);
	}
	exit(EXIT_SUCCESS);
}

void	heredoc_roop(t_token *token, t_heredoc *hd, int any_heredoc)
{
	char	*temp;

	signal_heredoc();
	temp = ft_itoa(hd->file_i++);
	hd->pid = fork();
	hd->filename = ft_strjoin(".temp", temp);
	ft_free(temp);
	hd->fd = open(hd->filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (!any_heredoc)
	{
		if (!any_infile(token, hd->j, hd->i))
			token[hd->j].last_doc = ft_strdup(hd->filename);
	}
	if (hd->pid == 0)
		heredoc_child(token, hd, &any_heredoc);
	ft_free(hd->filename);
	signal_ignore();
	wait_heredoc(hd);
}

void	do_heredoc(t_token *token, t_heredoc *hd, t_lenpos *lp)
{
	if (!ft_strncmp(&(token[hd->j].str[hd->i]), "<<", 2))
	{
		hd->i++;
		while (token[hd->j].str[++hd->i] == ' ')
			;
		lp->pos = hd->i;
		while (token[hd->j].str[hd->i] \
			&& token[hd->j].str[hd->i] != ' ' \
			&& token[hd->j].str[hd->i] != '<' \
			&& token[hd->j].str[hd->i] != '>')
		{
			lp->len++;
			hd->i++;
		}
		hd->here_doc = ft_substr(token[hd->j].str, lp->pos, lp->len);
		token[hd->j].here_doc[hd->hd_idx++] = ft_strdup(hd->here_doc);
		if (any_heredoc(token, hd->j, hd->i))
			heredoc_roop(token, hd, 1);
		else
			heredoc_roop(token, hd, 0);
		hd->i--;
		ft_free(hd->here_doc);
		signal_shell();
	}
}

int	parse_heredoc(t_token *t, int token_cnt)
{
	t_lenpos	lp;
	t_heredoc	hd;

	hd.j = -1;
	hd.file_i = 0;
	hd.status = 0;
	while (++hd.j < token_cnt)
	{
		hd.i = -1;
		hd.hd_idx = 0;
		if (t[hd.j].heredoc_cnt <= 0)
			continue ;
		t[hd.j].here_doc = ft_malloc(sizeof(char *) * t[hd.j].heredoc_cnt + 1);
		t[hd.j].here_doc[t[hd.j].heredoc_cnt] = NULL;
		while (t[hd.j].str[++hd.i])
		{
			lp.len = 0;
			lp.pos = 0;
			if (!is_quotes(t, t[hd.j].str[hd.i], hd.j))
				do_heredoc(t, &hd, &lp);
		}
	}
	if (hd.status)
		unlink_lastdoc(t, hd, token_cnt);
	return (hd.status);
}
