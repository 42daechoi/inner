#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

#include <stdio.h>

#define X_EVENT_KEYPRESS		2
#define X_EVENT_KEYRELEASE		3

#define KEYCODE_W   			13
#define KEYCODE_A   			0
#define KEYCODE_S   			1
#define KEYCODE_D   			2
#define KEYCODE_ESC				53

typedef	struct s_gameset
{
	int		x;
	int		y;
	int		map_width;
	int		map_height;
	char	*map_line;
} t_gameset;

void    read_map(char *file, t_gameset *gameset);