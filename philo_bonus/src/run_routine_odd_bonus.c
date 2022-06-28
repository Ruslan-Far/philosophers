/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_routine_odd_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:03:02 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 20:42:19 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	run_routine_odd(t_philo *p)
{
	int	i;
	int	len;

	while (1)
	{
		if (p->id % 2 == 0)
			sem_wait(p->even);
		else if (p->id != p->len)
			sem_wait(p->odd);
		else
		{
			i = 0;
			len = p->len / 2;
			while (i < len)
			{
				sem_wait(p->odd_last);
				i++;
			}
		}
		ft_take_forks(p);
		ft_eat_odd(p);
		ft_sleep_odd(p);
		ft_think_odd(p);
	}
}
