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
	return (0);
}

int get_next_line(char **line)
{
	static char	*stdinput;
	char		*buff;
	int			rdsize;
	char		*temp;
	int			nl_idx;
	int			i = -1;

	buff = malloc(2 * sizeof(char));
	if (!buff)
		return (-1);
	if (!stdinput)
	{
		stdinput = ft_strdup("", 0);
		while ((rdsize = read(0, buff, 1) > 0))
		{
			buff[1] = '\0';;
			temp = stdinput;
			stdinput = ft_strjoin(temp, buff);
			free(temp);
		}
		if (rdsize == -1)
			return (-1);
	}
	free(buff);
	if ((nl_idx = get_nl_idx(stdinput)))
	{
		*line = ft_strdup(stdinput, nl_idx);
		stdinput = stdinput + nl_idx + 1;
		return (1);
	}
	*line = ft_strdup(stdinput, ft_strlen(stdinput));
	return (0);
}

int main(void)
{
	char 	*line;
	int	ret;

	line = NULL;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("%d %s\n", ret, line);
	free(line);
	system("leaks a.out");
}
