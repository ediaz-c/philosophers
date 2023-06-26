/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:37:36 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/26 19:51:19 by ediaz--c         ###   ########.fr       */
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
			printf("[%d] philo %d is dead\n", (ft_actual_time() - p->time), p->id);
		}
	}
}

void	ft_dead_philo(t_vars *v)
{
	t_philo	*p;
	int		i;
	int		is_dead;

	p = v->philo;
	while (1)
	{
		
	}
}