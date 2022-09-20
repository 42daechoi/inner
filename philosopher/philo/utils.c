/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:58:44 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/07 17:52:25 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	print_err(char *str, int errno)
{
	printf("%s\n", str);
	return (errno);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res < 0)
			return ((sign + 1) / -2);
	}
	return ((long long)(res * sign));
}

void	ft_usleep(long long time)
{
	long long	starttime;

	starttime = get_time();
	while (1)
	{
		if (get_time() - starttime >= time)
			break ;
		usleep(128);
	}
}

void	waitforend(t_philo *philo, t_info info)
{
	int	i;

	i = -1;
	while (++i < info.philo_cnt)
		pthread_join(philo[i].thread, NULL);
}
