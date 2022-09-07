/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:39:24 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/17 17:57:33 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	get_malloc_size(int n)
{
	int	size;
	int	nb;

	size = 0;
	if (n == -2147483648)
		return (12);
	if (n == 0)
		return (2);
	nb = ft_abs(n);
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	if (n < 0)
		size++;
	return (size + 1);
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	i;
	long	nb;

	arr = (char *)ft_malloc(sizeof(char) * get_malloc_size(n));
	if (!arr)
		return (NULL);
	if (n == 0)
		ft_strlcpy(arr, "0", 2);
	else
	{
		i = 0;
		nb = ft_abs((long)n);
		while (nb > 0)
		{
			arr[i++] = (nb % 10) + '0';
			nb /= 10;
		}
		if (n < 0)
			arr[i++] = '-';
		arr[i] = '\0';
		ft_strrev(arr);
	}
	return (arr);
}
