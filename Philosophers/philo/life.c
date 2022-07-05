/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:03:22 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/14 18:30:14 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_forks_down(t_philo *philo)
{
	pthread_mutex_unlock(&philo->pointer->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->pointer->forks[philo->left_fork]);
}

void	ft_sleepthink(t_philo *philo)
{
	if (philo->time_after_eat != philo->pointer->n_philo_eat)
	{
		pthread_mutex_lock(philo->pointer->mutex);
		printf("Time : %lu| \x1b[32mPhilo %d\x1b[0m is sleeping\n",
			get_time() - philo->pointer->start, philo->philo_id);
		pthread_mutex_unlock(philo->pointer->mutex);
		ft_wait(philo->pointer->time_to_sleep);
		pthread_mutex_lock(philo->pointer->mutex);
		printf("Time : %lu| \x1b[32mPhilo %d\x1b[0m is thinking\n",
			get_time() - philo->pointer->start, philo->philo_id);
		pthread_mutex_unlock(philo->pointer->mutex);
	}
}

void	ft_life(t_philo *philo)
{
	while (!philo->pointer->death && philo->time_after_eat
		!= philo->pointer->n_philo_eat)
	{
		pthread_mutex_lock(&philo->pointer->forks[philo->right_fork]);
		pthread_mutex_lock(philo->pointer->mutex);
		printf("Time :%lu| \x1b[32mPhilo %d\x1b[0m has taken the right fork\n",
			get_time() - philo->pointer->start, philo->philo_id);
		pthread_mutex_unlock(philo->pointer->mutex);
		pthread_mutex_lock(&philo->pointer->forks[philo->left_fork]);
		pthread_mutex_lock(philo->pointer->mutex);
		printf("Time : %lu| \x1b[32mPhilo %d\x1b[0m has taken the left fork\n",
			get_time() - philo->pointer->start, philo->philo_id);
		pthread_mutex_unlock(philo->pointer->mutex);
		pthread_mutex_lock(philo->pointer->mutex);
		philo->time_last_eat = get_time();
		printf("Time : %lu| \x1b[32mPhilo %d\x1b[0m is eating\n",
			get_time() - philo->pointer->start, philo->philo_id);
		pthread_mutex_unlock(philo->pointer->mutex);
		ft_wait(philo->pointer->time_to_eat);
		ft_forks_down(philo);
		ft_sleepthink(philo);
		philo->time_after_eat++;
	}
}
