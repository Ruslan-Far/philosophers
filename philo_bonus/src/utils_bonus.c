/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:43:59 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/03/09 21:53:06 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

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

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sem_close(t_philo *p)
{
	sem_close(p->sem_died);
	sem_close(p->forks);
	sem_close(p->odd);
	sem_close(p->odd_last);
	sem_close(p->even);
	sem_close(p->num_eat_exit);
	sem_close(p->out_fork1);
	sem_close(p->out_fork2);
	sem_close(p->out_eat);
	sem_close(p->out_sleep);
	sem_close(p->out_think);
}

void	ft_sem_unlink(void)
{
	sem_unlink("/sem_died");
	sem_unlink("/forks");
	sem_unlink("/odd");
	sem_unlink("/odd_last");
	sem_unlink("/even");
	sem_unlink("/num_eat_exit");
	sem_unlink("/out_fork1");
	sem_unlink("/out_fork2");
	sem_unlink("/out_eat");
	sem_unlink("/out_sleep");
	sem_unlink("/out_think");
}
