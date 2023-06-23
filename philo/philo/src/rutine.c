/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:09:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/23 19:50:37 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static void	ft_take_forks(t_philo *p)
// {
// }

void	*rutine(void *philo)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = philo;
	p->time_init = ft_actual_time();
	while (i != p->laps && p->is_dead == 0)
	{
		//take forks
		//eat
		//sleep
		//think
		//die
		
		i++;
	}
	return (0);
}
