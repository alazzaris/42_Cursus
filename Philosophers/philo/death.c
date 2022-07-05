/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:06:12 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/14 17:06:22 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_info *args)
{
	int				i;
	unsigned long	curr_time;

	while (1)
	{
		i = -1;
		while (++i < args->n_philo)
		{
			usleep(1000);
			if (args->philo[i].time_after_eat == args->n_philo_eat)
				return (1);
			if (get_time() - args->philo[i].time_last_eat
				> (unsigned long)args->time_to_die)
			{
				args->death = 1;
				pthread_mutex_lock(args->mutex);
				printf("\x1b[31mPhilo %d died time: %lu\n",
					i + 1, get_time() - args->start);
				return (1);
			}
		}
	}
	return (0);
}
