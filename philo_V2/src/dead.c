/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:48:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 17:00:49 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_philo_dead(t_philo *p, int id)
{
	p[id].is_dead = 1;
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
		if ((args->tdie < p[i].last_eat))
		{
			ft_notify_philos(args, p);
			return (ft_philo_dead(p, i));
		}
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
		if (p[i].laps == args->n_eats)
			philos_finish++;
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
	while (!ft_is_dead(p))
	{}
	return (0);
}