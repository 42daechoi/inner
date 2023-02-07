#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int gfd;

void change_dir(char **av, int i)
{
	if (i != 3)
		pe("error: cd: bad arguments\n");
	else if (chdir(av[1]) == -1)
	{

	}
}

void exe(char **av, int i, char **env)
{
	int fd[2];
	int pid;
	int ispipe = 0;

	if (av[i] && strcmp(av[i], "|"))
		ispipe = 1;
	if (ispipe && pipe(fd) == -1)
	{
		pe();
		exit(1);
	}
	if ((pid = fork()) == -1)
	{
		pe();
		exit(1);
	}
	else if (pid == 0)
	{
		av[i] == NULL;
		close(fd[0]);
		dup2(gfd, 0);
		if (ispipe)
			dup2(fd[1], 1);
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
		if (i == 0)
			continue ;
		if (!strcmp(av[i], "cd"))
			change_dir(av, i);
		else
			exe(av, i, env);
		av += i;
	}
	return (0);
}