/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:05:02 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/13 09:53:06 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_take_forks(t_philo *p)
{
	if (pthread_mutex_lock(&p->fork_left) == 0)
	{
		if (ft_philo_msg(p, "has taken the left fork", LEFT) == 0)
			return (0);
		if (p->fork_right == NULL)
			return (ft_philo_alone(p));
		else if (pthread_mutex_lock(p->fork_right) == 0)
		{
			if (ft_philo_msg(p, "has taken the right fork", RIGHT) == 0)
				return (0);
			return (1);
		}
	}
	return (0);
}

int	ft_drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->fork_left);
	if (p->fork_right != NULL)
		pthread_mutex_unlock(p->fork_right);
	return (1);
}

int	ft_eat(t_philo *p)
{
	long	atime;

	if (ft_philo_msg(p, "is eating", COMER) == 0)
		return (0);
	pthread_mutex_lock(p->mod);
	p->last_eat = ft_timer(p);
	pthread_mutex_unlock(p->mod);
	atime = ft_actual_time();
	while (ft_actual_time() - atime < p->teat)
	{
		usleep(1000);
	}
	ft_drop_forks(p);
	return (1);
}

int	ft_sleep(t_philo *p)
{
	long	atime;

	if (ft_philo_msg(p, "is sleeping", DORMIR) == 0)
		return (0);
	atime = ft_actual_time();
	while (ft_actual_time() - atime < p->tsleep)
	{
		usleep(1000);
	}
	return (1);
}

int	ft_think(t_philo *p)
{
	if (ft_philo_msg(p, "is thinking", PENSAR) == 0)
		return (0);
	return (1);
}
