/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:29:41 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/13 18:29:41 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_info *args)
{
	int	i;

	free(args->forks);
	free(args->philo);
	free(args->mutex);
	i = 0;
	while (i < args->n_philo)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
}

static void	create_thread(t_info *args)
{
	int	i;

	i = 0;
	args->start = get_time();
	while (i < args->n_philo)
	{
		pthread_create(&args->philo[i].thread, NULL,
			(void *)ft_life, &args->philo[i]);
		usleep(100);
		i += 2;
	}
	i = 1;
	while (i < args->n_philo)
	{
		pthread_create(&args->philo[i].thread, NULL,
			(void *)ft_life, &args->philo[i]);
		usleep(100);
		i += 2;
	}
	if (ft_death(args))
		return ;
	i = -1;
	while (++i < args->n_philo)
		pthread_join(args->philo[i].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_info	args;

	if (argc != 5 && argc != 6)
		ft_args_error();
	args.n_philo = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	if (args.n_philo <= 0 || args.time_to_die <= 0 || args.time_to_eat <= 0
		|| args.time_to_sleep <= 0)
	{
		ft_args_error();
		return (1);
	}
	args.death = 0;
	if (argc == 6)
		args.n_philo_eat = ft_atoi(argv[5]);
	else
		args.n_philo_eat = -1;
	if (ft_create_fork(&args))
		return (1);
	create_thread(&args);
	ft_free(&args);
	return (0);
}
