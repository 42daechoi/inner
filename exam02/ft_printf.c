#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	init_info(t_info *info)
{
	info->width = 0;
	info->prec = -1;
	info->type = '0';
}

int	ft_digitlen(int n, int base)
{
	int i = 1;
	while (n /= base)
		i++;
	return (i);
}

void	ft_putnbr_base(long long n, int base)
{
	char *dec = "0123456789";
	char *hex = "0123456789abcdef";

	if (n < 0)
		n = -n;
	if (n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else
	{
		if (base == 10)
			write(1, &dec[n], 1);
		else
			write(1, &hex[n], 1);
	}
}

int	format_int(int n, t_info *info)
{
	int i = -1;
	int	ret = 0;
	int n_len;

	n_len = ft_digitlen(n, 10);
	if (info->prec == 0 && n == 0)
	{
		i = -1;
		while (++i < info->width)
		{
			write(1, " ", 1);
			ret++;
		}
		return (ret);
	}
	if (info->prec < n_len)
		info->prec = n_len;
	if (n < 0)
		info->prec++;
	while (++i < info->width - info->prec)
	{
		write(1, " ", 1);
		ret++;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n_len++;
	}
	i = -1;
	while (++i < info->prec - n_len)
	{
		write(1, "0", 1);
		ret++;
	}
	ret += n_len;
	ft_putnbr_base(n, 10);
	return (ret);
}

int	format_string(char *s, t_info *info)
{
	int s_len = 0;
	int	i = -1;
	int ret = 0;

	if (!s)
		s = "(null)";
	while (s[s_len])
		s_len++;
	if (info->prec != -1 && s_len > info->prec)
		s_len = info->prec;
	i = -1;
	while (++i < info->width - s_len)
	{
		write(1, " ", 1);
		ret++;
	}
	i = -1;
	while (++i < s_len)
	{
		write(1, &s[i], 1);
		ret++;
	}
	return (ret);
}

int	format_unsignedint(unsigned int n, t_info *info)
{
	int i = -1;
	int	ret = 0;
	int n_len;

	n_len = ft_digitlen(n, 16);
	if (info->prec == 0 && n == 0)
	{
		i = -1;
		while (++i < info->width)
		{
			write(1, " ", 1);
			ret++;
		}
		return (ret);
	}
	if (info->prec < n_len)
		info->prec = n_len;
	if (n < 0)
		info->prec++;
	while (++i < info->width - info->prec)
	{
		write(1, " ", 1);
		ret++;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n_len++;
	}
	i = -1;
	while (++i < info->prec - n_len)
	{
		write(1, "0", 1);
		ret++;
	}
	ret += n_len;
	ft_putnbr_base(n, 16);
	return (ret);
}

int parse_format(va_list ap, t_info *info)
{
	if (info->type == 'd')
		return (format_int(va_arg(ap, int), info));
	else if (info->type == 's')
		return (format_string(va_arg(ap, char *), info));
	else if (info->type == 'x')
		return (format_unsignedint(va_arg(ap, unsigned int), info));
	return (0);
}

int	parse_info(t_info *info, char *str, int *i, va_list ap)
{
	while (str[++(*i)])
	{
		if (str[*i] >= '0' && str[*i] <= '9' && info->prec == -1)
			info->width = info->width * 10 + (str[*i] - '0');
		else if (str[*i] == '.')
			info->prec = 0;
		else if (str[*i] >= '0' && str[*i] <= '9' && info->prec == 0)
			info->prec = info->prec * 10 + (str[*i] - '0');
		else if (str[*i] == 'd' || str[*i] == 's' || str[*i] == 'x')
		{
			info->type = str[*i];
			break ;
		}
	}
	return (parse_format(ap, info));
}

int check_spell(t_info *info, va_list ap, char *str)
{
	int i = -1;
	int	ret = 0;

	while (str[++i])
	{
		if (str[i] == '%')
		{
			ret += parse_info(info, str, &i, ap);
			init_info(info);
		}
		else
		{
			write(1, &str[i], 1);
			ret++;
		}
	}
	return (ret);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	t_info	info;
	int		ret;

	if (!str)
		return (-1);
	init_info(&info);
	va_start(ap, str);
	ret = check_spell(&info, ap, (char *)str);
	va_end(ap);
	return (ret);
}

