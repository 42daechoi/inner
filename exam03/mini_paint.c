#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_info
{
	char type;
	float x;
	float y;
	float r;
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
	int i;
	char *map;

	if (fscanf(file, "%d %d %c\n", width, height, backchar) != 3)
		return (NULL);
	if (*width <= 0 || *width > 300 || *height <= 0 || *height > 300)
		return (NULL);
	if (!(map = malloc((*width) * (*height) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < *width * *height)
		map[i] = *backchar;
	return (map);
}

int get_flag(float x, float y, t_info *info)
{
	float distance;
	distance = sqrtf(powf(x - info->x, 2.) + powf(y - info->y, 2.));
	if (distance <= info->r)
	{
		if (info->r - distance < 1.)
			return (2);
		return (1);
	}
	return (0);
}

void draw_circle(int width, int height, t_info *info, char *map)
{
	int i = -1;
	int j;
	int flag;

	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			flag = get_flag((float)j, (float)i, info);
			if ((info->type == 'c' && flag == 2) || (info->type == 'C' && flag))
				map[i * width + j] = info->fillchar;
		}
	}
}

int read_l(FILE *file, int width, int height, char *map)
{
	t_info info;
	int	rdsize;

	while ((rdsize = fscanf(file, "%c %f %f %f %c\n", &info.type, &info.x, &info.y, &info.r, &info.fillchar)) == 5)
	{
		if (info.r <= 0. || (info.type != 'c' && info.type != 'C'))
			return (0);
		draw_circle(width, height, &info, map);
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
	FILE	*file;
	int		width;
	int		height;
	char     backchar;
	char 	*map;

	width = 0;
	height = 0;
	map = NULL;
	if (ac != 2)
		return (ft_exit(file, map, "Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_exit(file, map, "Error: Operation file corrupted\n"));
	if (!(map = read_fl(file, &width, &height, &backchar)))
		return (ft_exit(file, map, "Error: Operation file corrupted\n"));
	if (!(read_l(file, width, height, map)))
		return (ft_exit(file, map, "Error: Operation file corrupted\n"));
	draw_all(width, height, map);
	return (0);
}