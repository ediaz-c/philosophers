/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:37:36 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/30 11:28:53 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_dead(t_vars *v)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = v->philo;
	while (i < v->args.nb_phs)
	{
		if (p[i].tdie <= (ft_actual_time() - p[i].last_eat))
		{
			printf("[%ld] philo %d is dead\n", (ft_actual_time() - p->time), p->id);
			return (0);
		}
	}
	return (1);
}

void	ft_dead_philo(t_vars *v)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = v->philo;
	while (1)
	{
		if (ft_check_dead(v) == 0)
			break ;
	}
	while (i < v->args.nb_phs)
	{
		p[i].is_dead = 1;
		i++;
	}
}