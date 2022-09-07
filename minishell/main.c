/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:28:58 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 23:12:55 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_builtin_fd(t_token token)
{
	int	fd;
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (token.outfile == NULL)
		return (0);
	while (token.outfile[len])
		len++;
	while (i < len)
	{
		if (token.append_flag[i] == 1)
			fd = open(token.outfile[i++], \
			O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			fd = open(token.outfile[i++], \
			O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (i != len)
			close(fd);
	}
	return (fd);
}

void	exec(t_token *token, char **copy_envp, int token_cnt, char *str)
{
	if (token_len(token) == 1 && do_builtin_one(token, copy_envp) == 1)
		;
	else
		start_fork(token, copy_envp);
	free_all_token(token, token_cnt, str);
}

void	init(int ac, char **av, char ***copy_envp, char **envp)
{
	struct termios	term;

	ac++;
	av[0]++;
	g_status = 0;
	terminal_init(&term);
	*copy_envp = envpcopy(envp);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	int		token_cnt;
	t_token	*token;
	char	**copy_envp;

	init(ac, av, &copy_envp, envp);
	signal_shell();
	while (1)
	{
		token_cnt = 0;
		str = readline("minishell % ");
		if (!str)
			ctrl_d();
		if (check_syntax(str))
			continue ;
		add_history(str);
		token = malloc_token(str, &token_cnt);
		init_token(token, token_cnt);
		if (parse_token(token, token_cnt, copy_envp, str))
			continue ;
		exec(token, copy_envp, token_cnt, str);
	}
	free_all_envp(copy_envp, 0);
	return (0);
}
