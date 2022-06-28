/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:55:36 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 20:59:23 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define _XOPEN_SOURCE 500
# define TIME_USLEEP 100

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h> 

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_eat;
	long			current_num_eat;
	long			start_time;
	long			last_eat_time;
	int				len;
	int				is_close;
	int				t_is_close;
	pid_t			*pid;
	sem_t			*sem_died;
	sem_t			*forks;
	sem_t			*odd;
	sem_t			*odd_last;
	sem_t			*even;
	sem_t			*num_eat_exit;
	sem_t			*out_fork1;
	sem_t			*out_fork2;
	sem_t			*out_eat;
	sem_t			*out_sleep;
	sem_t			*out_think;
}					t_philo;

int		ft_atoi(const char *str);
long	get_time(void);
void	ft_sem_close(t_philo *p);
void	ft_sem_unlink(void);

void	simulate(t_philo *philo, int len);

t_philo	*init(int *args, int num_argc);

void	run_routine_one(t_philo *philo);
void	run_routine_odd(t_philo *philo);
void	run_routine_even(t_philo *philo);

void	ft_exit(t_philo *p);
void	ft_exit_num_eat(t_philo *p);

void	ft_take_forks(t_philo *p);
void	ft_eat_odd(t_philo *p);
void	ft_eat_even(t_philo *p);
void	ft_sleep_odd(t_philo *p);
void	ft_sleep_even(t_philo *p);
void	ft_think_odd(t_philo *p);
void	ft_think_even(t_philo *p);

#endif