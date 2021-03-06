/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:07:36 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/20 15:54:23 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_cmd_line(char **av, t_pipe *p)
{
	if (*av[3] == 0 || *av[2] == 0)
		ft_printerr("command not found");
	p->file[0] = ft_strdup(av[1]);
	p->file[1] = ft_strdup(av[4]);
	p->cmd0 = ft_split(av[2], ' ');
	p->cmd1 = ft_split(av[3], ' ');
	if (!p->file[0] || !p->file[1] || !p->cmd0 || !p->cmd1)
		ft_printerr("malloc error");
}

char	*set_path_cmd(char *cmd, t_pipe *p)
{
	char	*path_cmd;
	int		i;
	char	*temp;

	i = 0;
	if (ft_strchr(cmd, '/') > 0)
		return (cmd);
	temp = ft_strjoin("/", cmd);
	while (p->path[i])
	{
		path_cmd = ft_strjoin(p->path[i], temp);
		if (access(path_cmd, X_OK) != -1)
		{
			free(temp);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	free(temp);
	return (NULL);
}

void	parse_path(char **envp, t_pipe *p)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 6) == envp[i])
			break ;
		i++;
	}
	p->path = ft_split(&(envp[i][5]), ':');
	if (!p->path)
		ft_printerr("malloc error");
	p->path_cmd0 = set_path_cmd(p->cmd0[0], p);
	p->path_cmd1 = set_path_cmd(p->cmd1[0], p);
	if (!p->path_cmd0 || !p->path_cmd1)
		ft_printerr("command not found or malloc error");
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	p;
	int		fd[2];

	if (ac != 5)
		ft_printerr("argument error");
	parse_cmd_line(av, &p);
	parse_path(envp, &p);
	if (pipe(fd) == -1)
		ft_printerr("pipe error");
	if (pipex(p, fd, envp) == -1)
		ft_printerr("pipex error");
	return (0);
}
