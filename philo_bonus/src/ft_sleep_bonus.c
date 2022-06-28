/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:57:36 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 21:00:04 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static void	ft_sem_post_odd_last(t_philo *p)
{
	int	i;
	int	len;

	i = 0;
	len = p->len / 2;
	while (i < len)
	{
		sem_post(p->odd);
		i++;
	}
}

void	ft_sleep_odd(t_philo *p)
{
	long	current_time;

	current_time = get_time();
	if (current_time - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->out_sleep);
	printf("%ld %d is sleeping\n", current_time - p->start_time, p->id);
	sem_post(p->out_sleep);
	sem_post(p->forks);
	sem_post(p->forks);
	if (p->id % 2 == 0)
		sem_post(p->odd_last);
	else if (p->id != p->len)
		sem_post(p->even);
	else
		ft_sem_post_odd_last(p);
	current_time += p->time_to_sleep;
	while (get_time() < current_time
		&& !(get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
}

void	ft_sleep_even(t_philo *p)
{
	long	current_time;

	current_time = get_time();
	if (current_time - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	if (p->num_eat != -1 && p->id % 2 == 0 && p->current_num_eat == p->num_eat)
		ft_exit_num_eat(p);
	sem_wait(p->out_sleep);
	printf("%ld %d is sleeping\n", current_time - p->start_time, p->id);
	sem_post(p->out_sleep);
	sem_post(p->forks);
	sem_post(p->forks);
	if (p->id % 2 == 0)
		sem_post(p->odd);
	else
		sem_post(p->even);
	current_time += p->time_to_sleep;
	while (get_time() < current_time
		&& !(get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
}
