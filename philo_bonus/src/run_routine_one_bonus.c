/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_routine_one_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:12:42 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 00:03:38 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static void	ft_take_fork(t_philo *p)
{
	if (get_time() - p->last_eat_time >= p->time_to_die)
		ft_exit(p);
	sem_wait(p->forks);
	printf("%ld %d has taken a fork\n", get_time() - p->start_time, p->id);
}

void	run_routine_one(t_philo *p)
{
	ft_take_fork(p);
	while (!(get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
	ft_exit(p);
}
