/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:58:41 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:49:43 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_pwd_start(char **envp, char **pwd_address, char **oldpwd_address)
{
	int	i;

	i = 0;
	*pwd_address = NULL;
	*oldpwd_address = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PWD", 3) == 0)
			*pwd_address = envp[i];
		if (ft_strncmp(envp[i], "OLDPWD", 6) == 0)
			*oldpwd_address = envp[i];
		i++;
	}
}

int	move_dir(t_token token, char *home)
{
	if (token.option[1] == NULL || token.option[1][0] == '\0')
		return (return_home(home));
	else
		return (return_not_home(token));
}

void	change_pwd(char *pwd_address, char **envp)
{
	t_token	token;
	char	*temp;
	char	*cwd;

	if (!pwd_address)
		return ;
	cwd = getcwd(NULL, 0);
	temp = ft_strjoin("PWD=", cwd);
	token.option = ft_malloc(sizeof(char *) * 3);
	token.option[0] = ft_strdup("export");
	token.option[1] = temp;
	token.option[2] = NULL;
	do_export(token, envp, 0);
	ft_free(token.option[0]);
	ft_free(token.option[1]);
	ft_free(token.option);
	ft_free(cwd);
}

void	change_oldpwd(char *cur, char *oldpwd_address, char **envp)
{
	t_token	token;
	char	*temp;

	if (!oldpwd_address)
		return ;
	temp = ft_strjoin("OLDPWD=", cur);
	token.option = ft_malloc(sizeof(char *) * 3);
	token.option[0] = ft_strdup("export");
	token.option[1] = temp;
	token.option[2] = NULL;
	do_export(token, envp, 0);
	ft_free(token.option[0]);
	ft_free(token.option[1]);
	ft_free(token.option);
}

int	change_dir(t_token token, char **envp)
{
	char	*pwd_address;
	char	*oldpwd_address;
	char	*temp;
	char	*cur;

	cur = getcwd(NULL, 0);
	temp = NULL;
	get_pwd_start(envp, &pwd_address, &oldpwd_address);
	if (move_dir(token, get_home(envp)))
	{
		ft_free(cur);
		return (1);
	}
	change_pwd(pwd_address, envp);
	change_oldpwd(cur, oldpwd_address, envp);
	ft_free(cur);
	return (1);
}
