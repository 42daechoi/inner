#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int gfd;

void p_e(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	write(2, str, i);
}

void change_dir(char **av, int i)
{
	if (i != 3)
		p_e("error: cd: bad arguments\n");
	else if (chdir(av[1]) == -1)
	{
		p_e("error: cd: cannot change directory to ");
		p_e(av[1]);
		p_e("\n");
	}
}

void exe(char **av, int i, char **env)
{
	int pid;
	int fd[2] = {-1, -2};
	int ispipe = 0;

	if (av[i] && !strcmp(av[i], "|"))
		ispipe = 1;
	if (ispipe && pipe(fd) == -1)
	{
		p_e("error: fatal\n");
		exit(1);
	}
	if ((pid = fork()) == -1)
	{
		p_e("error: fatal\n");
		exit(1);
	}
	else if (pid == 0)
	{
		av[i] = NULL;
		close(fd[0]);
		dup2(gfd, 0);
		if (ispipe)
			dup2(fd[1], 1);
		// if (gfd)
		// 	close(gfd);
		// close(fd[1]);
		if (execve(*av, av, env) == -1)
		{
			p_e("error: cannot execute ");
			p_e(*av);
			p_e("\n");
		}
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		if (gfd)
			close(gfd);
		if (ispipe)
			gfd = dup(fd[0]);
		close(fd[0]);
	}
}

int main(int ac, char **av, char **env)
{
	int i;

	if (ac == 1)
		return (0);
	while (*av)
	{
		av++;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (!i)
			continue ;
		if (!strcmp(*av, "cd"))
			change_dir(av, i);
		else
			exe(av, i, env);
		av += i;
	}
	return (0);
}