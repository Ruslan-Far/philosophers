/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:57:29 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 21:00:35 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_eat_odd(t_philo *p)
{
	long	current_time;

	current_time = get_time();
	if (current_time - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->out_eat);
	printf("%ld %d is eating\n", current_time - p->start_time, p->id);
	sem_post(p->out_eat);
	if (p->num_eat != -1)
		p->current_num_eat++;
	if (p->num_eat != -1 && p->id == p->len && p->current_num_eat == p->num_eat)
		ft_exit_num_eat(p);
	p->last_eat_time = current_time;
	current_time += p->time_to_eat;
	while (get_time() < current_time
		&& !(get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
}

void	ft_eat_even(t_philo *p)
{
	long	current_time;

	current_time = get_time();
	if (current_time - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->out_eat);
	printf("%ld %d is eating\n", current_time - p->start_time, p->id);
	sem_post(p->out_eat);
	if (p->num_eat != -1)
		p->current_num_eat++;
	p->last_eat_time = current_time;
	current_time += p->time_to_eat;
	while (get_time() < current_time
		&& !(get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
}
