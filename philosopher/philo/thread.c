/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:34:32 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/06 21:22:51 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*each_thread(t_philo *philo)
{
	if ((philo->me % 2))
		ft_usleep(philo->info->e_time / 2);
	while (42)
	{
		pthread_mutex_lock(&philo->info->catchdrace);
		if (philo->end_flag || philo->info->isdead)
			break ;
		pthread_mutex_unlock(&philo->info->catchdrace);
		philo_do(philo);
	}
	pthread_mutex_unlock(&philo->info->catchdrace);
	return (0);
}

int	is_all_eat(t_philo *philo, t_info info)
{
	int	i;

	i = -1;
	while (++i < info.philo_cnt)
	{
		pthread_mutex_lock(&philo->info->catchdrace);
		if (!philo[i].end_flag)
		{
			pthread_mutex_unlock(&philo->info->catchdrace);
			return (0);
		}
		pthread_mutex_unlock(&philo->info->catchdrace);
	}
	return (1);
}

int	is_dead(t_philo *philo, t_info *info)
{
	int			i;
	long long	curtime;

	while (!is_all_eat(philo, *info))
	{
		i = -1;
		while (++i < info->philo_cnt)
		{
			pthread_mutex_lock(&philo->info->catchdrace);
			curtime = get_time();
			if (curtime - philo[i].last_eat >= info->d_time)
			{
				printf("%lld %d died\n", \
				curtime - philo[i].start_time, philo[i].me + 1);
				info->isdead = 1;
				pthread_mutex_unlock(&philo->info->catchdrace);
				return (1);
			}
			pthread_mutex_unlock(&philo->info->catchdrace);
		}
		usleep(2500);
	}
	return (0);
}

int	is_solo(t_philo *philo, t_info info)
{
	if (info.philo_cnt == 1)
	{
		pthread_mutex_lock(philo->leftfork);
		philo_print(philo, philo->me, "has taken a fork");
		usleep(info.d_time);
		philo_print(philo, philo[0].me, "died");
		return (1);
	}
	return (0);
}

int	make_thread(t_philo *philo, t_info *info)
{
	int	i;

	if (is_solo(philo, *info))
		return (0);
	i = -1;
	while (++i < info->philo_cnt)
	{
		philo[i].last_eat = get_time();
		if (pthread_create(&philo[i].thread, \
			NULL, (void *)each_thread, &philo[i]))
			return (1);
	}
	is_dead(philo, info);
	waitforend(philo, *info);
	return (0);
}
