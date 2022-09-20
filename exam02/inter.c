#include <unistd.h>

int main(int ac, char **av)
{
	int i = -1;
	int j;
	int k;
	int flag = 1;

	if (ac == 3)
	{
		while (av[1][++i])
		{
			flag = 1;
			j = -1;
			while (av[2][++j])
			{
				if (av[1][i] == av[2][j])
				{
					k = -1;
					while (++k < i)
					{
						if (av[1][k] == av[1][i])
							flag = 0;
					}
					if (flag == 1)
						write(1, &av[1][i], 1);
					break;
				}
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
