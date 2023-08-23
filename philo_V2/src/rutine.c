/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:07:52 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 18:37:30 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *p)
{
	pthread_mutex_lock(p->mod);
	if (p->is_dead != 0)
		return (pthread_mutex_unlock(p->mod), 1);
	return (pthread_mutex_unlock(p->mod), 0);
}

void	*philo_rutine(void *philo)
{
	t_philo	*p;
	int	laps;
	int	i;

	p = philo;
	pthread_mutex_lock(p->mod);
	laps = p->n_eats;
	i = p->laps;
	pthread_mutex_unlock(p->mod);
	if (!p->first_to_eat)
		usleep(200);
	ft_is_dead(p);
	while (++i != laps)
	{
		if (!ft_take_forks(p) || ft_is_dead(p))
			break ;
		if (!ft_eat(p) || ft_is_dead(p))
			break ;
		if (!ft_drop_forks(p) || ft_is_dead(p))
			break ;
		if (!ft_sleep(p) || ft_is_dead(p))
			break ;
		if (!ft_think(p) || ft_is_dead(p))
			break ;
	}
	pthread_mutex_unlock(&p->fork_left);
	pthread_mutex_unlock(p->fork_right);
	return (0);
}
