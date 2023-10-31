/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:33:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/31 09:17:33 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_thread_philos(t_philo *p, int n_philos)
{
	int	i;
	int	err;

	i = -1;
	err = 0;
	while (++i < n_philos)
	{
		p[i].time = ft_actual_time();
		if (pthread_create(&p[i].tid, NULL, philo_rutine, &p[i]) != 0)
			err = 1;
	}
	if (err)
		return (ft_error("Thread error"));
	return (1);
}

static void	ft_free_all(t_args *args, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		free(p[i].mod);
		free(p[i].mod_die);
	}
	free(p[0].is_dead);
	free(p);
	free(args->id_finish);
}

static void	ft_join_threads(t_args *args, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		pthread_join(p[i].tid, NULL);
	}
}

static int	ft_init_philosophers(t_vars *vars)
{
	t_args	*args;
	t_philo	*philo;

	args = &vars->args;
	philo = vars->philos;
	if (!ft_thread_philos(philo, args->n_philo))
		return (0);
	ft_check_dead(args, philo);
	ft_join_threads(args, philo);
	ft_free_all(args, philo);
	return (1);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (!ft_check_ac(ac))
		return (1);
	if (!ft_check_argv(av))
		return (1);
	if (!ft_init_vars(&vars, av, ac))
		return (1);
	if (!ft_init_philosophers(&vars))
		return (1);
	return (0);
}
