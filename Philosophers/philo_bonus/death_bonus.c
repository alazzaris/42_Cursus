/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:08 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/19 16:47:51 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_death(t_philo *philo)
{
	unsigned long	now_time;

	while (1)
	{
		now_time = get_time();
		if (philo->n_phil_eat == philo->pointer->n_phil_eat)
			return (NULL);
		if (now_time - philo->time_last_eat
			>= (unsigned long)philo->pointer->time_to_die)
		{
			philo->death = 1;
			sem_wait(philo->pointer->semaphore);
			printf("\033[0;31m%d died  | time : %lu\n",
				philo->philo_id, now_time - philo->pointer->start);
			kill_processes(philo->pointer);
			close_unlink_semas(philo->pointer);
			free(philo->pointer->pid);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}
