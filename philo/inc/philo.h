/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:01:00 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/11 23:04:05 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define _XOPEN_SOURCE 500
# define TIME_USLEEP 100

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_eat;
	long			current_num_eat;
	long			start_time;
	long			last_eat_time;
	int				len;
	pthread_t		tid;
	pthread_mutex_t	*mutex_check_died;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*out_fork1;
	pthread_mutex_t	*out_fork2;
	pthread_mutex_t	*out_eat;
	pthread_mutex_t	*out_sleep;
	pthread_mutex_t	*out_think;
	struct s_philo	*p_arr;
}					t_philo;

int		ft_atoi(const char *str);
long	get_time(void);
void	ft_free(t_philo *philos, int len);
void	ft_destroy_mutexes(t_philo *p);

t_philo	*gen_philos(int *args, int len);

int		ft_take_forks(int *count, t_philo *p);
int		ft_eat(int *died, long *num_eat, t_philo *p);
int		ft_sleep(int *count, int *even_odd, t_philo *p);
int		ft_think(int *count, t_philo *p);

int		check_died_hunger(int *count, t_philo *p);

void	*run_routine(void *p);

#endif