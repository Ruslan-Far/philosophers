/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:13:26 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/09 21:40:15 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static void	simulate_one(t_philo *philo)
{
	philo->start_time = get_time();
	philo->last_eat_time = philo->start_time;
	*(philo->pid) = fork();
	if (*(philo->pid) == 0)
	{
		philo->id = 1;
		run_routine_one(philo);
	}
}

static void	simulate_odd(t_philo *philo, int len)
{
	int		i;

	i = 0;
	philo->start_time = get_time();
	philo->last_eat_time = philo->start_time;
	while (i < len)
	{
		philo->id = i + 1;
		philo->pid[i] = fork();
		if (philo->pid[i] == 0)
			run_routine_odd(philo);
		i++;
	}
}

static void	simulate_even(t_philo *philo, int len)
{
	int		i;

	i = 0;
	philo->start_time = get_time();
	philo->last_eat_time = philo->start_time;
	while (i < len)
	{
		philo->id = i + 1;
		philo->pid[i] = fork();
		if (philo->pid[i] == 0)
			run_routine_even(philo);
		i++;
	}
}

void	simulate(t_philo *philo, int len)
{
	int	status;
	int	i;

	if (philo->num_eat != 0)
	{
		if (len == 1)
			simulate_one(philo);
		else if (len % 2 == 1)
			simulate_odd(philo, len);
		else
			simulate_even(philo, len);
		i = 0;
		waitpid(-1, &status, 0);
		while (i < len)
			kill(philo->pid[i++], SIGKILL);
	}
	free(philo->pid);
	ft_sem_close(philo);
	free(philo);
}
