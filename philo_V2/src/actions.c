/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:05:02 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 17:53:38 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_take_forks(t_philo *p)
{
	if (ft_is_dead(p))
		return (0);
	if (pthread_mutex_lock(&p->fork_left) == 0)
	{
		if (ft_is_dead(p))
		return (pthread_mutex_unlock(&p->fork_left), 0);
		ft_philo_msg(p, "has taken the left fork", LEFT);
		if (p->fork_right == NULL)
			return (ft_philo_alone(p));
		if (pthread_mutex_lock(p->fork_right) == 0)
		{
			if (ft_is_dead(p))
				return (pthread_mutex_unlock(&p->fork_left), pthread_mutex_unlock(p->fork_right),0);
			ft_philo_msg(p, "has taken the right fork", RIGHT);
			return (1);
		}
	}
	return (0);
}

int ft_drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->fork_left);
	pthread_mutex_unlock(p->fork_right);
	return (1);
}

int	ft_eat(t_philo *p)
{
	if (ft_is_dead(p))
		return (0);
	ft_philo_msg(p, "is eating", COMER);
	if (ft_is_dead(p))
		return (0);
	pthread_mutex_lock(p->mod);
	p->last_eat = ft_timer(p);
	pthread_mutex_unlock(p->mod);
	if (ft_is_dead(p))
		return (0);
	usleep(p->teat * 1000);
	return (1);
}

int	ft_sleep(t_philo *p)
{
	if (ft_is_dead(p))
		return (0);
	ft_philo_msg(p, "is sleeping", DORMIR);
	if (ft_is_dead(p))
		return (0);
	usleep(p->tsleep * 1000);
	return (1);
}

int	ft_think(t_philo *p)
{
	if (ft_is_dead(p))
		return (0);
	ft_philo_msg(p, "is thinking", PENSAR);
	if (ft_is_dead(p))
		return (0);
	return (1);
}
