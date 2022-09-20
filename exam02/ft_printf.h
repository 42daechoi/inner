#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_info
{
	int		width;
	int		prec;
	char	type;
}	t_info;

int ft_printf(const char *str, ...);

#endif
