/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:56:36 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/09 21:06:02 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	int		args[5];
	t_philo	*philo;

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
	ft_sem_unlink();
	philo = init(args, argc - 1);
	simulate(philo, args[0]);
	ft_sem_unlink();
}
