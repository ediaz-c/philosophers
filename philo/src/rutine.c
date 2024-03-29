/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:07:52 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/13 09:59:54 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *p)
{
	if (*p->is_dead)
	{
		ft_drop_forks(p);
		return (1);
	}
	return (0);
}

static void	ft_finish_philo(t_philo *p, int laps)
{
	p->laps = laps;
	ft_drop_forks(p);
}

void	*philo_rutine(void *philo)
{
	t_philo	*p;
	int		laps;
	int		i;

	p = philo;
	laps = p->n_eats;
	i = -1;
	ft_wait_to_eat(p);
	ft_is_dead(p);
	while (++i != laps)
	{
		if (!ft_take_forks(p) || !ft_eat(p) || !ft_sleep(p) || !ft_think(p))
			break ;
	}
	ft_finish_philo(p, i);
	return (0);
}
