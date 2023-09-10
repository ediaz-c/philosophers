/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:33:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/09/08 12:50:53 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_thread_philos(t_philo *p, int n_philos)
{
	int	i;

	i = -1;
	while (++i < n_philos)
	{
		p[i].time = ft_actual_time();
		if (pthread_create(&p[i].tid, NULL, philo_rutine, &p[i]) != 0)
			ft_error("Thread error");
	}
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

static void	ft_init_philosophers(t_vars *vars)
{
	t_args	*args;
	t_philo	*philo;

	args = &vars->args;
	philo = vars->philos;
	ft_thread_philos(philo, args->n_philo);
	ft_check_dead(args, philo);
	ft_join_threads(args, philo);
	ft_free_all(args, philo);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	ft_check_ac(ac);
	ft_check_argv(av);
	ft_init_vars(&vars, av, ac);
	ft_init_philosophers(&vars);
}
