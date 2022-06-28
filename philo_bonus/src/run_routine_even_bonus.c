/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_routine_even_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:50:16 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 20:42:10 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	run_routine_even(t_philo *p)
{
	while (1)
	{
		if (p->id % 2 == 0)
			sem_wait(p->even);
		else
			sem_wait(p->odd);
		ft_take_forks(p);
		ft_eat_even(p);
		ft_sleep_even(p);
		ft_think_even(p);
	}
}
