/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:59:59 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/23 18:24:53 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_vars(t_vars *v, char **args)
{
	v->args.nb_phs = ft_atoi(args[1]);
	v->args.tdie = ft_atoi(args[2]);
	v->args.tdie = ft_atoi(args[3]);
	v->args.tsleep = ft_atoi(args[4]);
	if (args[5] != NULL)
		v->args.nb_eats = ft_atoi(args[5]);
	else
		v->args.nb_eats = -1;
}

void	ft_init_philos(t_vars *v)
{
	t_philo	*p;
	int		i;

	p = v->philo;
	i = 0;
	while (i < v->args.nb_phs)
	{
		p[i].id = i + 1;
		p[i].is_dead = 0;
		p[i].laps = v->args.nb_eats;
		p[i].fork_right = NULL;
		pthread_mutex_init(&p[i].fork_left, NULL);
		if (v->args.nb_phs == 1)
			return ;
		p[i].fork_right = &p[(i + 1) % i].fork_left;
		i++;
	}
}
