/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:38:18 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/23 17:38:19 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	free_all_envp(char **envp, int flag)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_free(envp[i]);
		envp[i++] = NULL;
	}
	ft_free(envp);
	envp = NULL;
	if (flag != 0)
		exit(0);
	return (1);
}

void	find_builtin(t_token *token, int *kind)
{
	if (ft_strcmp("cd", token[0].option[0]) == 0)
		*kind = CD;
	if (ft_strcmp("echo", token[0].option[0]) == 0)
		*kind = ECH;
	if (ft_strcmp("env", token[0].option[0]) == 0)
		*kind = ENV;
	if (ft_strcmp("exit", token[0].option[0]) == 0)
		*kind = EXIT;
	if (ft_strcmp("export", token[0].option[0]) == 0)
		*kind = EXPORT;
	if (ft_strcmp("pwd", token[0].option[0]) == 0)
		*kind = PWD;
	if (ft_strcmp("unset", token[0].option[0]) == 0)
		*kind = UNSET;
}

void	exe_builtin_one(t_token *token, int kind, char **envp)
{
	if (kind == CD)
		change_dir(token[0], envp);
	else if (kind == ECH)
		print_echo(token[0]);
	else if (kind == ENV)
		print_env(envp);
	else if (kind == EXIT)
		print_exit(token[0]);
	else if (kind == EXPORT)
		do_export(token[0], envp, 0);
	else if (kind == PWD)
		print_pwd();
	else if (kind == UNSET)
		print_unset(token[0], envp);
}

int	do_builtin_one(t_token *token, char **envp)
{
	int	kind;
	int	fd;
	int	oldfd;

	kind = -1;
	find_builtin(token, &kind);
	if (kind == -1)
		return (0);
	oldfd = dup(STDOUT_FILENO);
	fd = open_outfile(token, 0);
	if (fd > 0)
		ft_stdout(fd);
	exe_builtin_one(token, kind, envp);
	dup2(oldfd, STDOUT_FILENO);
	return (1);
}
