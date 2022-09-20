#include <unistd.h>
#include <stdio.h>

void left(char *s)
{
	int i = -1;
	int j;
	int flag = 1;

	while (s[++i])
	{
		j = -1;
		while (++j < i)
		{
			if (s[i] == s[j])
			{
				flag = 0;
				break ;
			}
			flag = 1;
		}
		if (flag == 1)
			write(1, &s[i], 1);
	}
}

void right(char *s, char *s2)
{
	int i = -1;
	int j;
	int flag = 1;

	while (s2[++i])
	{
		j = -1;
		while (s[++j])
		{
			if (s2[i] == s[j])
			{
				flag = 0;
				break ;
			}
			flag = 1;
		}
		j = -1;
		while (++j < i && flag == 1)
		{
			if (s2[i] == s2[j])
			{
				flag = 0;
				break ;
			}
			flag = 1;
		}
		if (flag == 1)
			write(1, &s2[i], 1);
	}
}

int main(int ac, char **av)
{
	int i;
	int j;

	if (ac != 3)
		write(1, "\n", 1);
	else
	{
		left(av[1]);
		right(av[1], av[2]);
	}
	return (0);
}	
			 
