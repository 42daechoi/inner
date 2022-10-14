#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

typedef struct s_info
{
	char c;
	float x;
	float y;
	float width;
	float height;
	char fillchar;
}	t_info;

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_exit(FILE *file, char *map, char *str)
{
	if (file)
		fclose(file);
	if (map)
		free(map);
	write(1, str, ft_strlen(str));
	return (1);
}

char *read_fl(FILE *file, int *width, int *height, char *backchar)
{
	char *map;
	int i = -1;

	if (fscanf(file, "%d %d %c\n", width, height, backchar) != 3)
		return (NULL);
	if (*width <= 0 || *width > 300 || *height <= 0 || *height > 300)
		return (NULL);
	if (!(map = malloc(*width * *height * sizeof(char))))
		return (NULL);
	while (++i < *width * *height)
		map[i] = *backchar;
	return (map);
}

int get_flag(float x, float y, t_info *info)
{
	if (x < info->x || x > info->x + info->width || y < info->y || y > info->y + info->height)
		return (0);
	if (x - info->x < 1. || (info->x + info->width) - x < 1. || y - info->y < 1. || (info->y + info->height) - y < 1.)
		return (2);
	return (1);
}

void draw_rec(int width, int height, char *map, t_info *info)
{
	int i = -1, j;
	int flag;

	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			flag = get_flag((float)j, (float)i, info);
			if ((info->c == 'r' && flag == 2) || (info->c == 'R' && flag))
				map[i * width + j] = info->fillchar;
		}
	}
}

int read_l(FILE *file, int width, int height, char *map)
{
	t_info info;
	int rdsize;

	while ((rdsize = fscanf(file, "%c %f %f %f %f %c\n", &info.c, &info.x, &info.y, &info.width, &info.height, &info.fillchar)) == 6)
	{
		if ((info.c != 'r' && info.c != 'R') || info.width <= 0. || info.height <= 0.)
			return (0);
		draw_rec(width, height, map, &info);
	}
	if (rdsize != -1)
		return (0);
	return (1);
}

void draw_all(int width, int height, char *map)
{
	int i = -1;
	while (++i < width * height)
	{
		write(1, &map[i], 1);
		if (i % width == width - 1)
			write(1, "\n", 1);
	}
}

int main(int ac, char **av)
{
	FILE *file = NULL;
	int width;
	int height;
	char backchar;
	char *map = NULL;

	if (ac != 2)
		return (ft_exit(file, map, "Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_exit(file, map, "Error: Operation file corrupted\n"));
	if (!(map = read_fl(file, &width, &height, &backchar)))
		return (ft_exit(file, map, "Error: Operation file corrupted\n"));
	if (!read_l(file, width, height, map))
		return (ft_exit(file, map, "Error: Operation file corrupted\n"));
	draw_all(width, height, map);
	fclose(file);
	free(map);
	return (0);
}