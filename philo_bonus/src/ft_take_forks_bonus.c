/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:57:33 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 20:31:46 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_take_forks(t_philo *p)
{
	if (get_time() - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->forks);
	sem_wait(p->out_fork1);
	printf("%ld %d has taken a fork\n", get_time() - p->start_time, p->id);
	sem_post(p->out_fork1);
	if (get_time() - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->forks);
	sem_wait(p->out_fork2);
	printf("%ld %d has taken a fork\n", get_time() - p->start_time, p->id);
	sem_post(p->out_fork2);
}
