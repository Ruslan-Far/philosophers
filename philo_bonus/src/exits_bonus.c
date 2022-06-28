/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:56:56 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/12 20:59:46 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_exit(t_philo *p)
{
	sem_wait(p->sem_died);
	printf("%ld %d died\n", get_time() - p->start_time, p->id);
	free(p->pid);
	ft_sem_close(p);
	free(p);
	exit(0);
}

void	ft_exit_num_eat(t_philo *p)
{
	sem_wait(p->num_eat_exit);
	free(p->pid);
	ft_sem_close(p);
	free(p);
	exit(0);
}
