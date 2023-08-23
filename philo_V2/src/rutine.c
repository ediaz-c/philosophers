/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:07:52 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 13:00:27 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *p)
{
	if (p->is_dead != 0)
		return (1);
	return (0);
}

void	*philo_rutine(void *philo)
{
	t_philo	*p;

	p = philo;
	if (!p->first_to_eat)
		usleep(150);
	ft_is_dead(p);
	while (p->laps != p->n_eats)
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
		p->laps++;
	}
	ft_unlock_all(p);
	return (0);
}
