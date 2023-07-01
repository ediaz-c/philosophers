/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:29:33 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/01 15:38:46 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_philos(t_vars *v)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = v->philo;
	while (i < v->args.nb_phs)
	{
		printf("ID: %d\n", p[i].id);
		// printf("IS DEAD: %d\n", p[i].is_dead);
		printf("LAPS: %d\n", p[i].laps);
		printf("Fork left: %p\n", (&p[i].fork_left));
		printf("Fork right: %p\n", p[i].fork_right);
		printf("Time init: %ld\n", p[i].time);
		printf("Time to die: %d\n", p[i].tdie);
		printf("Time to eat: %d\n", p[i].teat);
		printf("Time to sleep: %d\n", p[i].tsleep);
		printf("Is dead: %s\n", (p[i].is_dead)?"dead":"live");
		printf("Eat: %d\n\n", p[i].feat);
		
		
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac == 1)
		printf("./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [[number_of_times_each_philosopher_must_eat]\n");
	if (ac != 5 && ac != 6)
		ft_error("Numero de argumentos invalidos");
	if (ft_check_args(av) == 0)
		ft_error("Argumento invalido\n");
	ft_init_vars(&vars, av);
	vars.philo = malloc(sizeof(t_philo) * vars.args.nb_phs);
	if (vars.philo == NULL)
		ft_error("No alocada memoria");
	ft_init_philos(&vars);
	// check_philos(&vars);
	ft_init_threads(&vars);
	// system("leaks -q philo");
}
