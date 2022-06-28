/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:24:40 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/09 23:19:12 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	init_1_part_philos(t_philo *philos, int i, int *args, int num_argc)
{
	philos[i].id = i + 1;
	philos[i].time_to_die = args[1];
	philos[i].time_to_eat = args[2];
	philos[i].time_to_sleep = args[3];
	if (num_argc == 5)
		philos[i].num_eat = args[4];
	else
		philos[i].num_eat = -1;
	philos[i].current_num_eat = 0;
	philos[i].len = args[0];
}

static int	init_2_part_philos(t_philo *philos, int i, int *args)
{
	philos[i].mutex_check_died = philos[0].mutex_check_died;
	philos[i].out_fork1 = philos[0].out_fork1;
	philos[i].out_fork2 = philos[0].out_fork2;
	philos[i].out_eat = philos[0].out_eat;
	philos[i].out_sleep = philos[0].out_sleep;
	philos[i].out_think = philos[0].out_think;
	philos[i].left = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philos[i].left, NULL);
	if (args[0] == 1)
		return (0);
	if (i == args[0] - 1)
	{
		philos[0].right = philos[i].left;
		return (0);
	}
	philos[i + 1].right = philos[i].left;
	return (1);
}

t_philo	*gen_philos(int *args, int num_argc)
{
	t_philo			*philos;
	int				i;

	philos = malloc(sizeof(t_philo) * args[0]);
	philos[0].mutex_check_died = malloc(sizeof(pthread_mutex_t));
	philos[0].out_fork1 = malloc(sizeof(pthread_mutex_t));
	philos[0].out_fork2 = malloc(sizeof(pthread_mutex_t));
	philos[0].out_eat = malloc(sizeof(pthread_mutex_t));
	philos[0].out_sleep = malloc(sizeof(pthread_mutex_t));
	philos[0].out_think = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philos[0].mutex_check_died, NULL);
	pthread_mutex_init(philos[0].out_fork1, NULL);
	pthread_mutex_init(philos[0].out_fork2, NULL);
	pthread_mutex_init(philos[0].out_eat, NULL);
	pthread_mutex_init(philos[0].out_sleep, NULL);
	pthread_mutex_init(philos[0].out_think, NULL);
	i = 0;
	while (1)
	{
		init_1_part_philos(philos, i, args, num_argc);
		if (!init_2_part_philos(philos, i, args))
			break ;
		i++;
	}
	return (philos);
}
