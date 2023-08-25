/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:07:52 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/25 17:58:38 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *p)
{
	int	is_dead;

	pthread_mutex_lock(p->mod_die);
	is_dead = p->is_dead;
	pthread_mutex_unlock(p->mod_die);
	if (is_dead)
	{
		ft_drop_forks(p);
		return (1);
	}
	return (0);
}

static void	ft_finish_philo(t_philo *p, int laps)
{
	pthread_mutex_lock(p->mod);
	p->laps = laps;
	pthread_mutex_unlock(p->mod);
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
		if (!ft_take_forks(p))
			break ;
		if (!ft_eat(p))
			break ;
		if (!ft_sleep(p))
			break ;
		if (!ft_think(p))
			break ;
	}
	ft_finish_philo(p, i);
	return (0);
}
