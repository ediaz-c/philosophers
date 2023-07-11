/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:09:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/11 20:14:31 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_forks(t_philo *p, int take)
{
	if (ft_check_dead(p))
		return (0);
	if (take == 1)
	{
		if (pthread_mutex_lock(&p->fork_left) == 0)
		{
			if (ft_check_dead(p))
				return (0);
			ft_philo_msg(p, 0);
			if (p->fork_right && pthread_mutex_lock(p->fork_right) == 0)
				if (ft_check_dead(p))
					return (0);
			ft_philo_msg(p, 1);
		}
	}
	else
	{
		pthread_mutex_unlock(&p->fork_left);
		pthread_mutex_unlock(p->fork_right);
	}
	if (ft_check_dead(p))
		return (0);
	return (1);
}

static int	ft_eat(t_philo *p)
{
	if (ft_check_dead(p))
		return (0);
	ft_philo_msg(p, 2);
	pthread_mutex_lock(p->mod_philo);
	p->last_eat = ft_actual_time();
	pthread_mutex_unlock(p->mod_philo);
	usleep(p->teat * 1000);
	if (ft_check_dead(p))
		return (0);
	return (1);
}

static int	ft_sleep(t_philo *p)
{
	usleep(100);
	if (ft_check_dead(p))
		return (0);
	ft_philo_msg(p, 3);
	usleep(p->tsleep * 1000);
	if (ft_check_dead(p))
		return (0);
	return (1);
}

static int	ft_think(t_philo *p)
{
	if (ft_check_dead(p))
		return (0);
	ft_philo_msg(p, 4);
	if (ft_check_dead(p))
		return (0);
	return (1);
}

void	*rutine(void *philo)
{
	t_philo		*p;
	int			i;

	i = -1;
	p = philo;
	if ((p->id % 2) == 0)
		usleep(100);
	if (ft_check_dead(p))
		return (0);
	while (++i != p->laps && p->is_dead != -1)
	{
		if (!ft_forks(p, 1) || !ft_eat(p))
			break ;
		if (!ft_forks(p, 0))
			break ;
		if (!ft_sleep(p))
			break ;
		if (!ft_think(p))
			break ;
	}
	pthread_mutex_lock(p->mod_philo);
	p->laps = 0;
	pthread_mutex_unlock(p->mod_philo);
	return (0);
}
