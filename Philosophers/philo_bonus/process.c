/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:56:41 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/19 16:15:11 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_processes(t_info *info, int *pid)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			ft_new_philo(info, i);
		i++;
	}
}

void	kill_processes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		kill(info->pid[i], SIGINT);
		i++;
	}
}
