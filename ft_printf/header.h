/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:22:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/17 20:35:38 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_info
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	char	type;
	int		sharp;
	int		plus;
	int		space;
}	t_info;

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	putstr_va(int n, ...);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		str_format(char *s, t_info info);
int		char_format(char c, t_info info);
int		int_format(int n, t_info info);
char	*ft_itoa(long long n);
char	*padding(int zero_flag, int pad_len);
char	*ft_malloc_nbr_base(unsigned long nbr, char *base);
int		pointer_format(unsigned long n, t_info info);
char	*set_zpad(t_info info, char *abs);
int		unsignedint_format(unsigned int n, t_info info);
int		ft_printf(const char *str, ...);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*spec_flags(t_info info, int *print_len, char sign, unsigned int n);
char	*print_strformat(char *str, t_info info);
char	*sort_zpad(char *abs, char *zpad_str);
char	*set_itoa_str(t_info info, int n);
char	*set_pad_str(char *itoa_str, t_info info);
void	free_va(int n, ...);
char	*set_s(unsigned int n, t_info info);
int		check_spell(const char *str, va_list ap, t_info info);
int		parsing(const char *str, int *i, t_info *info);
int		print_format(va_list *ap, t_info info);
void	init_info(t_info *info);

#endif