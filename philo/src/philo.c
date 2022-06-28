/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:01:14 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/11 23:05:28 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	simulate(t_philo *philos, int len)
{
	int				i;
	t_philo			*watcher;
	long			current_time;

	i = 0;
	watcher = malloc(sizeof(t_philo));
	watcher->id = 0;
	watcher->len = len;
	watcher->num_eat = philos[0].num_eat;
	watcher->p_arr = philos;
	pthread_create(&watcher->tid, NULL, run_routine, watcher);
	usleep(500);
	current_time = get_time();
	while (i < len)
	{
		philos[i].start_time = current_time;
		philos[i].last_eat_time = philos[i].start_time;
		pthread_create(&philos[i].tid, NULL, run_routine, &philos[i]);
		i++;
	}
	pthread_join(watcher->tid, NULL);
	free(watcher);
}

int	main(int argc, char **argv)
{
	int		i;
	int		args[5];
	t_philo	*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	i = 0;
	while (i++ < argc - 1)
	{
		args[i - 1] = ft_atoi(argv[i]);
		if (args[i - 1] < 0)
		{
			printf("Argument must not be negative\n");
			return (0);
		}
	}
	if (args[0] == 0)
		return (0);
	philos = gen_philos(args, argc - 1);
	simulate(philos, args[0]);
	ft_free(philos, args[0]);
}
