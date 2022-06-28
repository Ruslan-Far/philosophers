/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:10:58 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 00:30:14 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_take_forks(int *died, t_philo *p)
{
	if (*died != 0 || get_time() - p->last_eat_time >= p->time_to_die)
		return (check_died_hunger(died, p));
	pthread_mutex_lock(p->left);
	pthread_mutex_lock(p->out_fork1);
	printf("%ld %d has taken a fork\n", get_time() - p->start_time, p->id);
	pthread_mutex_unlock(p->out_fork1);
	if (p->len != 1)
	{
		if (*died != 0 || get_time() - p->last_eat_time >= p->time_to_die)
			return (check_died_hunger(died, p));
		pthread_mutex_lock(p->right);
		pthread_mutex_lock(p->out_fork2);
		printf("%ld %d has taken a fork\n", get_time() - p->start_time, p->id);
		pthread_mutex_unlock(p->out_fork2);
	}
	return (1);
}

int	ft_eat(int *died, long *num_eat, t_philo *p)
{
	long	current_time;

	while (p->len == 1)
		if (!check_died_hunger(died, p))
			return (0);
	current_time = get_time();
	if (*died != 0 || current_time - p->last_eat_time >= p->time_to_die)
		return (check_died_hunger(died, p));
	pthread_mutex_lock(p->out_eat);
	printf("%ld %d is eating\n", current_time - p->start_time, p->id);
	pthread_mutex_unlock(p->out_eat);
	if (p->num_eat != -1)
		p->current_num_eat++;
	if (p->current_num_eat == p->num_eat)
	{
		pthread_mutex_lock(p->mutex_check_died);
		(*num_eat)++;
		pthread_mutex_unlock(p->mutex_check_died);
	}
	p->last_eat_time = current_time;
	while (get_time() < current_time + p->time_to_eat
		&& !(*died != 0 || get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
	return (1);
}

int	ft_sleep(int *died, int *even_odd, t_philo *p)
{
	long	current_time;

	current_time = get_time();
	if (*died != 0 || current_time - p->last_eat_time >= p->time_to_die)
		return (check_died_hunger(died, p));
	pthread_mutex_lock(p->out_sleep);
	printf("%ld %d is sleeping\n", current_time - p->start_time, p->id);
	pthread_mutex_unlock(p->out_sleep);
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(p->right);
	if (p->id % 2 == 1 && p->id != p->len)
		*even_odd = 1;
	else if (p->id % 2 == 1 && p->id == p->len)
		*even_odd = 0;
	else if (p->id % 2 == 0 && p->len % 2 == 1)
		*even_odd = 2;
	else
		*even_odd = 0;
	while (get_time() < current_time + p->time_to_sleep
		&& !(*died != 0 || get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
	return (1);
}

int	ft_think(int *died, t_philo *p)
{
	if (*died != 0 || get_time() - p->last_eat_time >= p->time_to_die)
		return (check_died_hunger(died, p));
	pthread_mutex_lock(p->out_think);
	printf("%ld %d is thinking\n",
		get_time() - ((t_philo *) p)->start_time, ((t_philo *) p)->id);
	pthread_mutex_unlock(p->out_think);
	return (1);
}
