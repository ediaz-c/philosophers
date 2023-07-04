/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:09:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/04 14:26:48 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_forks(t_philo *p, int take)
{
	if (take == 1)
	{
		if (pthread_mutex_lock(&p->fork_left) == 0)
		{
			pthread_mutex_lock(p->print);
			ft_philo_msg(p, 0);
			if (p->fork_right && pthread_mutex_lock(p->fork_right) == 0)
				ft_philo_msg(p, 1);
			pthread_mutex_unlock(p->print);
		}
	}
	else
	{
		pthread_mutex_unlock(&p->fork_left);
		pthread_mutex_unlock(p->fork_right);
	}
}

static void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->print);
	ft_philo_msg(p, 2);
	p->last_eat = ft_actual_time();
	usleep(p->teat * 1000);
	pthread_mutex_unlock(p->print);
}

int	ft_sleep(t_philo *p)
{
	pthread_mutex_lock(p->print);
	ft_philo_msg(p, 3);
	usleep(p->tsleep * 1000);
	pthread_mutex_unlock(p->print);
	return (1);
}

int	ft_think(t_philo *p)
{
	pthread_mutex_lock(p->print);
	ft_philo_msg(p, 4);
	pthread_mutex_unlock(p->print);
	return (1);
}

void	*rutine(void *philo)
{
	t_philo		*p;
	int			i;

	i = 0;
	p = philo;
	if ((p->id % 2) == 0)
		usleep(100);
	while (++i != p->laps && p->is_dead != -1)
	{
		ft_forks(p, 1);
		if (ft_check_dead(p))
			break ;
		ft_eat(p);
		ft_forks(p, 0);
		if (ft_check_dead(p))
			break ;
		ft_sleep(p);
		if (ft_check_dead(p))
			break ;
		ft_think(p);
		if (ft_check_dead(p))
			break ;
	}
	p->laps = 0;
	return (0);
}
