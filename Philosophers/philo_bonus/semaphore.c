/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:20:10 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/19 16:56:23 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_semaphores(t_info *info)
{
	sem_unlink("sims");
	sem_unlink("death");
	sem_unlink("semaphore");
	info->fork = sem_open("sims", O_CREAT, 0700, info->n_philo);
	if (info->fork == SEM_FAILED)
	{
		sem_close(info->fork);
		exit(1);
	}
	info->death_semaphore = sem_open("death", O_CREAT, 0700, 1);
	if (info->death_semaphore == SEM_FAILED)
	{
		sem_close(info->death_semaphore);
		exit(1);
	}
	info->semaphore = sem_open("semaphore", O_CREAT, 0700, 1);
	if (info->death_semaphore == SEM_FAILED)
	{
		sem_close(info->semaphore);
		exit(1);
	}
}

void	close_unlink_semas(t_info *info)
{
	if (info->fork)
	{
		sem_close(info->fork);
		sem_unlink("sims");
	}
	if (info->death_semaphore)
	{
		sem_close(info->death_semaphore);
		sem_unlink("death");
	}
	if (info->semaphore)
	{
		sem_close(info->semaphore);
		sem_unlink("semaphore");
	}
	exit(1);
}
