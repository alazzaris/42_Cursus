/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:09:49 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/14 17:09:50 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_philo(t_info *args, int i)
{
	args->philo[i].philo_id = i + 1;
	args->philo[i].right_fork = i;
	if (i == 0)
		args->philo[i].left_fork = args->n_philo - 1;
	else
		args->philo[i].left_fork = i - 1;
	args->philo[i].pointer = args;
	args->philo[i].time_after_eat = 0;
	args->philo[i].time_last_eat = get_time();
}

void	init_philo_struct(t_info *args)
{
	int	i;

	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
		{
			printf("\x1b[0;31mFailed to init mutex\n");
			ft_free(args);
			break ;
		}
		ft_create_philo(args, i);
		i++;
	}
}

int	ft_create_fork(t_info *args)
{
	args->philo = malloc(sizeof(t_philo) * args->n_philo);
	if (!args->philo)
		return (1);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	if (!args->forks)
	{
		free(args->philo);
		return (1);
	}
	args->mutex = malloc(sizeof(pthread_mutex_t) * 1);
	if (!args->mutex)
	{
		free(args->mutex);
		return (1);
	}
	init_philo_struct(args);
	return (0);
}
