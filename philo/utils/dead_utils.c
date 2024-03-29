/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:38:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/11/09 12:40:36 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_notify_philos(t_args *args, t_philo *p)
{
	int	i;

	i = -1;
	pthread_mutex_lock(p->print);
	while (++i < args->n_philo)
	{
		*p[i].is_dead = 1;
	}
	pthread_mutex_unlock(p->print);
}
