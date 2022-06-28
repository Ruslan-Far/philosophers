/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:53:11 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/11 23:42:34 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	control(t_philo *p, int *died, long *num_eat)
{
	while (1)
	{
		if (*died != 0 || *num_eat == p->len || p->num_eat == 0)
		{
			if (*died == 0 && (*num_eat == p->len || p->num_eat == 0))
				(*died)++;
			else
			{
				while (*died != p->len)
				{
				}
				(*died)++;
			}
			while (*died != p->len + 1)
			{
			}
			usleep(1000);
			return (0);
		}
	}
}

static int	ft_wait(t_philo *p, int *died, int *even_odd)
{
	if (!(p->len % 2 == 1 && p->id == p->len))
	{
		while ((p->id % 2 == *even_odd || *even_odd == 2)
			&& !(*died != 0 || get_time() - p->last_eat_time >= p->time_to_die))
			usleep(TIME_USLEEP);
	}
	while (p->id == p->len && p->len % 2 == 1 && *even_odd != 2 && p->len != 1
		&& !(*died != 0 || get_time() - p->last_eat_time >= p->time_to_die))
		usleep(TIME_USLEEP);
	return (1);
}

void	*run_routine(void *p)
{
	static int				died = 0;
	static long				num_eat = 0;
	static int				even_odd = 0;

	if (((t_philo *) p)->id == 0)
		if (!control((t_philo *) p, &died, &num_eat))
			return (NULL);
	pthread_detach(((t_philo *) p)->tid);
	while (1)
	{
		if (!ft_wait((t_philo *) p, &died, &even_odd))
			return (NULL);
		if (!ft_take_forks(&died, (t_philo *) p))
			return (NULL);
		if (!ft_eat(&died, &num_eat, (t_philo *) p))
			return (NULL);
		if (!ft_sleep(&died, &even_odd, (t_philo *) p))
			return (NULL);
		if (!ft_think(&died, (t_philo *) p))
			return (NULL);
	}
}
