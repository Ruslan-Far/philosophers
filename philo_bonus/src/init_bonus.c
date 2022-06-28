/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:04:11 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/09 22:07:52 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static void	init_sems(t_philo *philo, int *args)
{
	philo->sem_died = sem_open("/sem_died", O_CREAT, 0666, 1);
	if (philo->sem_died == SEM_FAILED)
		exit(0);
	philo->forks = sem_open("/forks", O_CREAT, 0666, args[0]);
	if (philo->forks == SEM_FAILED)
		exit(0);
	philo->odd = sem_open("/odd", O_CREAT, 0666, args[0] / 2);
	if (philo->odd == SEM_FAILED)
		exit(0);
	philo->even = sem_open("/even", O_CREAT, 0666, args[0] / 2);
	if (philo->even == SEM_FAILED)
		exit(0);
	philo->odd_last = sem_open("/odd_last", O_CREAT, 0666, 1);
	if (philo->odd_last == SEM_FAILED)
		exit(0);
	philo->num_eat_exit = sem_open("/num_eat_exit", O_CREAT, 0666, 1);
	if (philo->num_eat_exit == SEM_FAILED)
		exit(0);
}

static void	init_sems_out(t_philo *philo)
{
	philo->out_fork1 = sem_open("/out_fork1", O_CREAT, 0666, 1);
	if (philo->out_fork1 == SEM_FAILED)
		exit(0);
	philo->out_fork2 = sem_open("/out_fork2", O_CREAT, 0666, 1);
	if (philo->out_fork2 == SEM_FAILED)
		exit(0);
	philo->out_eat = sem_open("/out_eat", O_CREAT, 0666, 1);
	if (philo->out_eat == SEM_FAILED)
		exit(0);
	philo->out_sleep = sem_open("/out_sleep", O_CREAT, 0666, 1);
	if (philo->out_sleep == SEM_FAILED)
		exit(0);
	philo->out_think = sem_open("/out_think", O_CREAT, 0666, 1);
	if (philo->out_think == SEM_FAILED)
		exit(0);
}

t_philo	*init(int *args, int num_argc)
{
	t_philo			*philo;
	int				i;

	philo = malloc(sizeof(t_philo));
	philo->time_to_die = args[1];
	philo->time_to_eat = args[2];
	philo->time_to_sleep = args[3];
	if (num_argc == 5)
		philo->num_eat = args[4];
	else
		philo->num_eat = -1;
	philo->current_num_eat = 0;
	philo->len = args[0];
	philo->is_close = 0;
	philo->t_is_close = 0;
	philo->pid = malloc(sizeof(pid_t) * args[0]);
	init_sems(philo, args);
	init_sems_out(philo);
	i = 0;
	while (i++ < args[0] / 2)
		sem_wait(philo->even);
	sem_wait(philo->odd_last);
	return (philo);
}
