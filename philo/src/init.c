/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:59:59 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/08 19:39:55 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_vars(t_vars *v, char **args)
{
	v->args.nb_phs = ft_atoi(args[1]);
	v->args.tdie = ft_atoi(args[2]);
	v->args.teat = ft_atoi(args[3]);
	v->args.tsleep = ft_atoi(args[4]);
	if (args[5] != NULL)
		v->args.nb_eats = ft_atoi(args[5]);
	else
		v->args.nb_eats = -1;
}

void	ft_init_mutex(t_vars *v)
{
	t_philo			*p;
	int				i;
	pthread_mutex_t	write_status;

	i = 0;
	p = v->philo;
	if (pthread_mutex_init(&write_status, NULL) != 0)
		ft_error("mutex error");
	while (i < v->args.nb_phs)
	{
		p[i].mod_philo = malloc(sizeof(pthread_mutex_t));
		if (p[i].mod_philo == NULL)
			ft_error("malloc error");
		if (pthread_mutex_init(p[i].mod_philo, NULL) != 0)
			ft_error("mutex error");
		p[i].fork_right = NULL;
		p[i].print = &write_status;
		if (pthread_mutex_init(&p[i].fork_left, NULL) != 0)
			ft_error("mutex error");
		if (v->args.nb_phs == 1)
			return ;
		p[i].fork_right = &p[(i + 1) % v->args.nb_phs].fork_left;
		i++;
	}
}

void	ft_init_philos(t_vars *v)
{
	t_philo	*p;
	int		i;

	p = v->philo;
	i = -1;
	v->args.time_init = ft_actual_time();
	while (++i < v->args.nb_phs)
	{
		p[i].id = i + 1;
		p[i].is_dead = 0;
		p[i].laps = v->args.nb_eats;
		p[i].tdie = v->args.tdie;
		p[i].teat = v->args.teat;
		p[i].tsleep = v->args.tsleep;
		p[i].time = v->args.time_init;
		p[i].feat = (p[i].id % 2 == 0);
		p[i].last_eat = 0;
	}
	ft_init_mutex(v);
}

void	ft_init_threads(t_vars *v)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = v->philo;
	while (i < v->args.nb_phs)
	{
		if (pthread_create(&p[i].tid, NULL, rutine, &p[i]) != 0)
			ft_error("Thread error");
		i++;
	}
	ft_dead_philo(v);
	i = 0;
	while (i < v->args.nb_phs)
		pthread_join(p[i++].tid, NULL);
}
