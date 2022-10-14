#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str, int n)
{
	char *ret;
	int i = -1;

	if (!n)
		n = ft_strlen(str);
	ret = malloc((n + 1) * sizeof(char));
	while (++i < n)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = -1;
	char *str;
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);

	if (!s1 || !s2)
		return (NULL);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len++] = s2[i];
	str[s1_len] = '\0';
	return (str);
}

int	get_nl_idx(char *str)
{
	int i = -1;

	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

char *get_next_line(int fd)
{
	static char	*stdinput;
	char		buff[BUFFER_SIZE + 1];
	int			rdsize;
	char		*temp;
	int			nl_idx;
	char		*ret;
	int			i = -1;

	if (!stdinput)
	{
		stdinput = ft_strdup("", 0);
		while ((rdsize = read(fd, buff, BUFFER_SIZE) > 0))
		{
			buff[rdsize] = '\0';
			temp = stdinput;
			stdinput = ft_strjoin(temp, buff);
			free(temp);
		}
		if (rdsize == -1)
			return (NULL);
	}
	if (!*stdinput)
		return (NULL);
	if ((nl_idx = get_nl_idx(stdinput)))
	{
		ret = ft_strdup(stdinput, nl_idx);
		stdinput = stdinput + nl_idx + 1;
	}
	else
		ret = ft_strdup(stdinput, ft_strlen(stdinput));
	return (ret);
}

int main(void)
{
	char	*ret;

	while ((ret = get_next_line(0)))
	{
		printf("%s\n", ret);
		free(ret);
		ret = NULL;
	}
	printf("%s\n", ret);
	free(ret);;
	system("leaks a.out");
}
