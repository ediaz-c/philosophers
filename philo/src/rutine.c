/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:09:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/24 18:28:35 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_eat(t_philo *p)
{
	if (pthread_mutex_lock(&p->fork_left) == 0)
	{
		printf("[%ld] philo %d take left fork\n", (ft_actual_time() - p->time_init), p->id);
		if (p->fork_right && pthread_mutex_lock(p->fork_right) == 0)
		{
			printf("[%ld] philo %d take right fork\n", (ft_actual_time() - p->time_init), p->id);
			printf("[%ld] philo %d is eating\n", (ft_actual_time() - p->time_init), p->id);
			usleep(p->teat * 1000);
			pthread_mutex_unlock(p->fork_right);
		}
			pthread_mutex_unlock(&p->fork_left);
	}
	return (p->eaten);
}

int	ft_sleep(t_philo *p)
{
	printf("[%ld] philo %d is sleeping\n", (ft_actual_time() - p->time_init), p->id);
	usleep(p->tsleep * 1000);
	return (1);
}

void	*rutine(void *philo)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = philo;
	while (i != p->laps && *p->is_dead == 0)
	{
		ft_eat(p);
		// {
		// 	ft_sleep(p);
		// }
		
		//sleep
		//think
		//die
		//printf("%d\n\n", i);
		i++;
	}
	return (0);
}
