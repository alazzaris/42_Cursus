/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:12:22 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/19 16:33:35 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_new_philo(t_info *info, int i)
{
	t_philo	philo;

	philo.death = 0;
	philo.pointer = info;
	philo.n_phil_eat = 0;
	philo.philo_id = i + 1;
	philo.time_last_eat = get_time();
	pthread_create(&philo.thread, NULL, (void *)ft_death, &philo);
	ft_life(&philo);
	pthread_detach(philo.thread);
	exit(0);
}

void	ft_sleepthink(t_philo *philo)
{
	if (philo->n_phil_eat != philo->pointer->n_phil_eat)
	{
		sem_wait(philo->pointer->semaphore);
		printf("time : %lu | %d is sleeping\n",
			get_time() - philo->pointer->start, philo->philo_id);
		sem_post(philo->pointer->semaphore);
		ft_wait(philo->pointer->time_to_sleep);
		sem_wait(philo->pointer->semaphore);
		printf("time : %lu | %d is thinking\n",
			get_time() - philo->pointer->start, philo->philo_id);
		sem_post(philo->pointer->semaphore);
	}
}

void	ft_life(t_philo *philo)
{
	while (!philo->death
		&& philo->n_phil_eat != philo->pointer->n_phil_eat)
	{
		sem_wait(philo->pointer->fork);
		sem_wait(philo->pointer->semaphore);
		printf("time : %lu | %d has taken a fork\n",
			get_time() - philo->pointer->start, philo->philo_id);
		sem_post(philo->pointer->semaphore);
		sem_wait(philo->pointer->fork);
		sem_wait(philo->pointer->semaphore);
		printf("time : %lu | %d has taken a fork\n",
			get_time() - philo->pointer->start, philo->philo_id);
		sem_post(philo->pointer->semaphore);
		sem_wait(philo->pointer->semaphore);
		philo->time_last_eat = get_time();
		printf("time : %lu | %d is eating\n",
			get_time() - philo->pointer->start, philo->philo_id);
		sem_post(philo->pointer->semaphore);
		ft_wait(philo->pointer->time_to_eat);
		sem_post(philo->pointer->fork);
		sem_post(philo->pointer->fork);
		philo->n_phil_eat++;
		ft_sleepthink(philo);
	}
}
