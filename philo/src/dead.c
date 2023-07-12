/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:37:36 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/12 16:24:25 by Erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_all_thread_stop(t_vars *v)
{
	int	i;

	i = 0;
	if (v->args.nb_eats == -1)
		return (0);
	while (i < v->args.nb_phs)
	{
		pthread_mutex_lock(v->philo[i].mod_philo);
		if (v->philo[i].laps != 0)
			return (pthread_mutex_unlock(v->philo[i].mod_philo), 0);
		pthread_mutex_unlock(v->philo[i].mod_philo);
		i++;
	}
	return (1);
}

static int	ft_time_dead(t_vars *v)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = v->philo;
	while (i < v->args.nb_phs)
	{
		pthread_mutex_lock(p[i].mod_philo);
		if (p[i].laps != 0 && p[i].last_eat > 0 && (p[i].tdie
			<= ft_actual_time() - p[i].last_eat))
		{
			p[i].is_dead = 1;
			ft_philo_msg(&p[i], 5);
			pthread_mutex_unlock(p[i].mod_philo);
			return (0);
		}
		pthread_mutex_unlock(p[i].mod_philo);
		i++;
	}
	return (1);
}

int	ft_check_dead(t_philo *p)
{
	pthread_mutex_lock(p->mod_philo);
	if (p->is_dead != 0)
	{
		pthread_mutex_unlock(p->fork_right);
		pthread_mutex_unlock(&p->fork_left);
		pthread_mutex_unlock(p->print);
		pthread_mutex_unlock(p->mod_philo);
		return (1);
	}
	pthread_mutex_unlock(p->mod_philo);
	return (0);
}

void	ft_dead_philo(t_vars *v)
{
	t_philo	*p;
	int		i;
	int		is_dead;

	i = 0;
	is_dead = 0;
	p = v->philo;
	while (1)
	{
		if (ft_time_dead(v) == 0)
		{
			is_dead = 1;
			break ;
		}	
		if (ft_all_thread_stop(v))
			break ;
	}
	while (is_dead && i < v->args.nb_phs)
	{
		pthread_mutex_lock(p[i].mod_philo);
		if (p[i].is_dead != 1)
			p[i].is_dead = -1;
		pthread_mutex_unlock(p[i].mod_philo);
		i++;
	}
}
