/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:39:30 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/18 16:36:24 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_in(char c, char *set)
{
	while (true)
	{
		if (*set == '\0')
			return (c == '\0');
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

int	count_occur(char *str, char *charset)
{
	int		count;
	char	*previous;
	char	*next;
	char	*save_start;

	count = 0;
	previous = str;
	next = str;
	save_start = str;
	while (true)
	{
		if (is_in(*str, charset))
			next = str;
		if (previous == save_start && next - previous == 1
			&& !is_in(*previous, charset))
			count++;
		if (next - previous > 1)
			count++;
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	return (count);
}

int	add_part(char **entry, char *previous, int size, char *charset)
{
	if (is_in(previous[0], charset))
	{
		previous++;
		size--;
	}
	*entry = (char *)malloc(sizeof(char) * (size + 1));
	ft_strncpy(*entry, previous, size);
	(*entry)[size] = '\0';
	(*entry)[size + 1] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	*previous;
	char	*next;
	char	**array;

	array = ft_malloc(sizeof(char *) * (count_occur(str, charset) + 1));
	i = 0;
	previous = str;
	next = str;
	while (true)
	{
		if (is_in(*str, charset))
			next = str;
		if (i == 0 && next - previous == 1
			&& !is_in(*previous, charset))
			i += add_part(&array[i], previous, next - previous, charset);
		if (next - previous > 1)
			i += add_part(&array[i], previous, next - previous, charset);
		if (*(str) == '\0')
			break ;
		previous = next;
		str++;
	}
	array[i] = NULL;
	return (array);
}
