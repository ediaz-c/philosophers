/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:48:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/09/11 19:18:15 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_check_time_to_die(t_args *args, t_philo *p,
		int id, long int last_eat)
{
	int	suma;

	if ((args->n_philo == 1) && (ft_timer(&p[id]) > args->tdie))
		return (ft_notify_philos(args, p),
			ft_philo_msg(&p[id], "is dead", 6), 0);
	suma = last_eat + args->tdie;
	if (!args->id_finish[id])
	{
		if (ft_timer(&p[id]) > suma)
		{
			ft_notify_philos(args, p);
			return (ft_philo_msg(&p[id], "is dead", 6), 0);
		}
	}
	return (1);
}

static int	ft_check_laps(t_args *args, int id, int laps)
{
	int	i;

	i = -1;
	if (!args->id_finish[id])
	{
		if (laps == args->n_eats)
			args->id_finish[id] = 1;
		return (1);
	}
	while (++i < args->n_philo)
	{
		if (args->id_finish[i] == 0)
			return (1);
	}
	return (0);
}

void	ft_check_dead(t_args *args, t_philo *p)
{	
	int			i;
	long int	last_eat;

	while (1)
	{
		i = -1;
		while (++i < args->n_philo)
		{
			pthread_mutex_lock(p[i].mod);
			last_eat = p[i].last_eat;
			pthread_mutex_unlock(p[i].mod);
			if (ft_check_time_to_die(args, p, i, last_eat) == 0)
				break ;
			if (args->n_eats != -1)
			{
				if (ft_check_laps(args, i, p[i].laps) == 0)
					break ;
			}
		}
		if (i != args->n_philo)
			break ;
	}
}

int	ft_philo_alone(t_philo *p)
{
	int	i;

	i = 1;
	pthread_mutex_unlock(&p->fork_left);
	while (i && !ft_is_dead(p))
		i++;
	return (0);
}
