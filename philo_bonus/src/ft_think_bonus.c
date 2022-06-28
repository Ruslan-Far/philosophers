/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:57:19 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 00:25:09 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_think_odd(t_philo *p)
{
	long	current_time;

	current_time = get_time();
	if (current_time - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->out_think);
	printf("%ld %d is thinking\n",
		current_time - ((t_philo *) p)->start_time, ((t_philo *) p)->id);
	sem_post(p->out_think);
	current_time += 2 * p->time_to_eat - p->time_to_sleep;
	while (get_time() < current_time
		&& !(get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
	if (get_time() - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
}

void	ft_think_even(t_philo *p)
{
	long	current_time;

	current_time = get_time();
	if (current_time - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->out_think);
	printf("%ld %d is thinking\n",
		current_time - ((t_philo *) p)->start_time, ((t_philo *) p)->id);
	sem_post(p->out_think);
	current_time += p->time_to_eat - p->time_to_sleep;
	while (get_time() < current_time
		&& !(get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
	if (get_time() - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
}
