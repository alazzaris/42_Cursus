/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:57:03 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/19 16:32:51 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				n_phil_eat;
	int				death;
	int				pid;
	unsigned long	time_last_eat;
	struct s_info	*pointer;
}				t_philo;

typedef struct s_info
{
	unsigned long	start;
	int				n_philo;
	int				*pid;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_phil_eat;
	t_philo			*philo;
	sem_t			*fork;
	sem_t			*death_semaphore;
	sem_t			*semaphore;
}	t_info;

void			ft_semaphores(t_info *info);
void			close_unlink_semas(t_info *info);

unsigned long	get_time(void);
void			ft_wait(int time_to_wait);

void			ft_processes(t_info *info, int *pid);
void			kill_processes(t_info *info);
void			ft_philo(t_info *info);

int				ft_atoi(const char *str);

void			*ft_death(t_philo *philo);
void			ft_life(t_philo *philo);
void			ft_new_philo(t_info *info, int i);

#endif
