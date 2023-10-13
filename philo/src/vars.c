/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:20:57 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/13 10:03:26 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* arreglar returns*/
static void	ft_init_argv(t_args *args, char **argv, int argc)
{
	args->n_philo = ft_atoi(argv[1]);
	args->tdie = ft_atoi(argv[2]);
	args->teat = ft_atoi(argv[3]);
	args->tsleep = ft_atoi(argv[4]);
	args->id_finish = malloc(sizeof(int) * args->n_philo);
	if (args->id_finish == NULL)
		return ;
	ft_all_zero(args);
	if (argc == 6)
		args->n_eats = ft_atoi(argv[5]);
	else
		args->n_eats = UNLIMITED;
}

static void	ft_philo_mutex(t_args *args, t_philo *p)
{
	int				i;
	pthread_mutex_t	write_status;

	i = -1;
	ft_init_mutex(&write_status);
	while (++i < args->n_philo)
	{
		p[i].mod = ft_create_mutex();
		p[i].mod_die = ft_create_mutex();
		ft_init_mutex(p[i].mod);
		ft_init_mutex(p[i].mod_die);
		ft_init_mutex(&p[i].fork_left);
		p[i].print = &write_status;
		if (args->n_philo == 1)
			p[i].fork_right = NULL;
		else
			p[i].fork_right = &p[(i + 1) % args->n_philo].fork_left;
	}
}

static void	ft_init_philos(t_args *args, t_philo *p)
{
	int				i;
	atomic_int		*is_dead;

	i = -1;
	is_dead = malloc(sizeof(atomic_int));
	*is_dead = 0;
	args->time_init = ft_actual_time();
	while (++i < args->n_philo)
	{
		p[i].id = i + 1;
		p[i].is_dead = is_dead;
		p[i].time = args->time_init;
		p[i].last_eat = 0;
		p[i].laps = 0;
		p[i].first_to_eat = (p[i].id % 2 == 0);
		p[i].n_eats = args->n_eats;
		p[i].tdie = args->tdie;
		p[i].teat = args->teat;
		p[i].tsleep = args->tsleep;
	}
	ft_philo_mutex(args, p);
}

void	ft_init_vars(t_vars *vars, char **argv, int argc)
{
	ft_init_argv(&vars->args, argv, argc);
	vars->philos = malloc(sizeof(t_philo) * vars->args.n_philo);
	if (vars->philos == NULL)
		ft_error("Error malloc");
	ft_init_philos(&vars->args, vars->philos);
}
