/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:37:36 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/01 15:25:34 by ediaz--c         ###   ########.fr       */
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
		if (v->philo[i].laps != 0)
			return (0);
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
		if (p[i].last_eat > 0 && p[i].tdie <= (ft_actual_time() - p[i].last_eat))
		{
			p[i].is_dead = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_dead(t_philo *p)
{
	if (p->is_dead == 1)
	{
		ft_philo_msg("is dead", p, 4);
		return (1);
	}
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
		//printf("%d\n", ft_time_dead(v));
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
		if (p[i].is_dead != 1)
			p[i].is_dead = -1;
			i++;
	}
}