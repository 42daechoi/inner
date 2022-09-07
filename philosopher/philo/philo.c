/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:33:16 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/06 21:49:21 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, int me, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->info->catchdrace);
	time = get_time();
	if (!philo->end_flag && !philo->info->isdead)
		printf("%lld %d %s\n", time - philo->start_time, me + 1, str);
	pthread_mutex_unlock(&philo->info->catchdrace);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->leftfork);
	philo_print(philo, philo->me, "has taken a fork");
	pthread_mutex_lock(philo->rightfork);
	philo_print(philo, philo->me, "has taken a fork");
	philo_print(philo, philo->me, "is eating");
	pthread_mutex_lock(&philo->info->catchdrace);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->info->catchdrace);
	philo->eat_cnt++;
	ft_usleep(philo->info->e_time);
	pthread_mutex_unlock(philo->leftfork);
	pthread_mutex_unlock(philo->rightfork);
	pthread_mutex_lock(&philo->info->catchdrace);
	if (philo->eat_cnt == philo->info->min_eat)
		philo->end_flag = 1;
	pthread_mutex_unlock(&philo->info->catchdrace);
}

void	sleeping(t_philo *philo)
{
	philo_print(philo, philo->me, "is sleeping");
	ft_usleep(philo->info->s_time);
}

void	philo_do(t_philo *philo)
{
	eating(philo);
	sleeping(philo);
	philo_print(philo, philo->me, "is thinking");
}
