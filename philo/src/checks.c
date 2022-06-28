/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:12:06 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/11 23:05:30 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_hunger(t_philo *p)
{
	static int	count = 0;
	long		current_time;

	current_time = get_time();
	if (current_time - p->last_eat_time >= p->time_to_die)
	{
		pthread_mutex_lock(p->mutex_check_died);
		if (count == 0)
		{
			printf("%ld %d died\n", current_time - p->start_time, p->id);
			count++;
		}
		pthread_mutex_unlock(p->mutex_check_died);
		return (0);
	}
	return (1);
}

int	check_died_hunger(int *died, t_philo *p)
{
	if (*died != 0 || !check_hunger(p))
	{
		pthread_mutex_lock(p->mutex_check_died);
		(*died)++;
		pthread_mutex_unlock(p->mutex_check_died);
		pthread_mutex_unlock(p->left);
		if (p->len != 1)
			pthread_mutex_unlock(p->right);
		return (0);
	}
	return (1);
}
