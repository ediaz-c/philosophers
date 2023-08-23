/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:48:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 17:56:33 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_philo_dead(t_philo *p, int id)
{
	pthread_mutex_lock(p[id].mod);
	p[id].is_dead = 1;
	pthread_mutex_unlock(p[id].mod);
	ft_philo_msg(&p[id], "is dead", 6);
	return (0);
}

static int	ft_check_time_to_die(t_args *args, t_philo *p)
{
	int	i;

	i = -1;
	if ((args->n_philo == 1) && (ft_timer(&p[++i]) > args->tdie))
		return (ft_philo_dead(p, i));
	while (++i < args->n_philo)
	{
		pthread_mutex_lock(p[i].mod);
		if ((ft_timer(p) > p[i].last_eat + args->tdie) && args->n_eats != p[i].laps)
		{
			pthread_mutex_unlock(p[i].mod);
			ft_notify_philos(args, p);
			return (ft_philo_dead(p, i));
		}
		pthread_mutex_unlock(p[i].mod);
	}
	return (1);
}

static int	ft_check_laps(t_args *args, t_philo *p)
{
	int	i;
	int	philos_finish;

	i = -1;
	philos_finish = 0;
	while (++i < args->n_philo)
	{
		pthread_mutex_lock(p[i].mod);
		if (p[i].laps == args->n_eats)
			philos_finish++;
		pthread_mutex_unlock(p[i].mod);
	}
	if (philos_finish == args->n_philo)
		return (0);
	return (1);
}

void	ft_check_dead(t_args *args, t_philo *p)
{
	while (1)
	{
		if (ft_check_time_to_die(args, p) == 0)
			break ;
		if (args->n_eats != -1)
		{
			if (ft_check_laps(args, p) == 0)
				break ;
		}
	}
}

int ft_philo_alone(t_philo *p)
{
	pthread_mutex_unlock(&p->fork_left);
	while (!ft_is_dead(p))
	{}
	return (0);
}