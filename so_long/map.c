#include "solong.h"

void    read_map(char *file, t_gameset *gameset)
{
    int     fd;
    char    *line;
    char    *temp;

    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    gameset->map_height = 0;
    gameset->map_width = ft_strlen(line) - 1;
    gameset->map_line = line;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {
            temp = gameset->map_line;
            gameset->map_line = ft_strjoin(temp, line);
            free(temp);
            free(line);
        }
        gameset->map_height++;
    }
    close(fd);
}