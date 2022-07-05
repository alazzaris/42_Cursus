/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:06:24 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/19 17:44:53 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo(t_info *info)
{
	int	i;

	i = 0;
	info->start = get_time();
	info->pid = malloc(sizeof(int) * info->n_philo);
	if (!info->pid)
		exit(1);
	ft_processes(info, info->pid);
	while (i < info->n_philo)
	{
		waitpid(info->pid[i++], 0, 0);
	}
	kill_processes(info);
	close_unlink_semas(info);
	free(info->pid);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (argc != 5 && argc != 6)
		return (1);
	info.n_philo = ft_atoi(argv[1]);
	info.time_to_die = ft_atoi(argv[2]);
	info.time_to_eat = ft_atoi(argv[3]);
	info.time_to_sleep = ft_atoi(argv[4]);
	if (info.n_philo <= 0 || info.time_to_die <= 0
		|| info.time_to_sleep <= 0 || info.time_to_eat <= 0)
		return (1);
	if (argc == 6)
	{
		info.n_phil_eat = ft_atoi(argv[5]);
		if (info.n_phil_eat <= 0)
			return (1);
	}
	else
		info.n_phil_eat = -1;
	ft_semaphores(&info);
	ft_philo(&info);
	return (0);
}
