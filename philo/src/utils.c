/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:03:06 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/09 23:35:57 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	process_limit(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	num;
	int						sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == '\r' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num > 9223372036854775807)
			return (process_limit(sign));
	}
	return ((int) num * sign);
}

void	ft_free(t_philo *philos, int len)
{
	int	i;

	i = 0;
	ft_destroy_mutexes(philos);
	while (i < len)
	{
		free(philos[i].left);
		i++;
	}
	free(philos[0].mutex_check_died);
	free(philos[0].out_fork1);
	free(philos[0].out_fork2);
	free(philos[0].out_eat);
	free(philos[0].out_sleep);
	free(philos[0].out_think);
	free(philos);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_destroy_mutexes(t_philo *p)
{
	int	i;

	if (p->len == 1)
		pthread_mutex_destroy(p[0].left);
	else
	{
		i = 0;
		while (i < p->len)
			pthread_mutex_destroy(p[i++].left);
	}
	pthread_mutex_destroy(p[0].mutex_check_died);
	pthread_mutex_destroy(p[0].out_fork1);
	pthread_mutex_destroy(p[0].out_fork2);
	pthread_mutex_destroy(p[0].out_eat);
	pthread_mutex_destroy(p[0].out_sleep);
	pthread_mutex_destroy(p[0].out_think);
}
