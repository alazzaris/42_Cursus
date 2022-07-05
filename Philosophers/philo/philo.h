/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:59:59 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/13 17:59:59 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				time_after_eat;
	int				right_fork;
	int				left_fork;
	unsigned long	time_last_eat;
	struct s_info	*pointer;
}	t_philo;

typedef struct s_info
{
	unsigned long	start;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_philo_eat;
	int				death;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex;
}	t_info;

void			ft_philo(t_info *info, int i);
void			ft_args_error(void);
int				ft_create_fork(t_info *info);
int				ft_death(t_info *info);
void			ft_life(t_philo *philo);
void			ft_free(t_info *args);
unsigned long	get_time(void);
void			ft_wait(int time_to_wait);
int				ft_atoi(const char *str);

#endif
