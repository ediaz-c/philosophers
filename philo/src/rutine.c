/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:09:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/30 11:34:53 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_eat(t_philo *p)
{
	int	i;

	i = 0;
	if (!p->feat)
	{
		if (pthread_mutex_lock(&p->fork_left) == 0)
		{
			pthread_mutex_lock(p->print);
			ft_philo_msg("take left fork", p);
			if (p->fork_right && pthread_mutex_lock(p->fork_right) == 0)
			{
				ft_philo_msg("take right fork", p);
				ft_philo_msg("is eating", p);
				p->last_eat = (ft_actual_time() - p->time);
				i = 1;
				usleep(p->teat * 1000);
				pthread_mutex_unlock(p->fork_right);
			}
				pthread_mutex_unlock(p->print);
				pthread_mutex_unlock(&p->fork_left);
		}
	}
	else
		p->feat = 0;
	return (i);
}

int	ft_sleep(t_philo *p)
{
	pthread_mutex_lock(p->print);
	ft_philo_msg("is sleeping", p);
	usleep(p->tsleep * 1000);
	pthread_mutex_unlock(p->print);
	return (1);
}

int	ft_think(t_philo *p)
{
	pthread_mutex_lock(p->print);
	ft_philo_msg("is thinking", p);
	pthread_mutex_unlock(p->print);
	return(1);
}

void	*rutine(void *philo)
{
	t_philo		*p;
	int			i;

	i = 0;
	p = philo;
	while (i != p->laps && !p->is_dead)
	{
		if (ft_eat(p))
		{
			ft_sleep(p);
			ft_think(p);
		}
		else
			usleep(10);
		i++;
	}
	return (0);
}
