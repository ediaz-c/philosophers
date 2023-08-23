/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:33:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 13:00:49 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check(t_vars *vars)
{
	t_args	*args;
	t_philo	*p;

	args = &vars->args;
	p = vars->philos;
	/* VARS */
	printf(BRED"Vars\n"OFF);
	printf("Numero de filosofos: %d\n", args->n_philo);
	printf("Tiempo de vida: %d\n", args->tdie);
	printf("Tiempo para comer: %d\n", args->teat);
	printf("Tiempo para dormir: %d\n", args->tsleep);
	printf("Numero de comidas: %d\n", args->n_eats);
	printf("Tiempo de inicio (0): %ld\n", args->time_init);
	write(1, "\n", 1);

	for(int i = 0; i < args->n_philo; i++)
	{
		printf(BGREEN"Philo numero: %d\n"OFF, p[i].id);
		printf("Está muerto: %d (%s)\n", p[i].is_dead, ((p[i].is_dead)?"Muerto":"Vivo"));
		printf("Ultima comida: %ld\n", (args->time_init - p[i].last_eat));
		printf("Ultima comida: %ld\n", p[i].last_eat);
		printf("Laps: %d\n", p[i].laps);
		printf("¿Come primero?: %s\n", (p[i].first_to_eat?"Si":"No"));
		printf("Numero de comidas: %d\n", p[i].n_eats);
		printf("Tiempo de inicio (0): %ld\n", p[i].time);
		printf("Tiempo de vida: %d\n", p[i].tdie);
		printf("Tiempo para comer: %d\n", p[i].teat);
		printf("Tiempo para dormir: %d\n", p[i].tsleep);
		printf("Thread ID: %p\n", p[i].tid);
		printf("Puntero para modificar: %p\n", p[i].mod);
		printf("Puntero para escribir: %p\n", p[i].print);
		printf("Puntero del ternedor derecho: %p\n", p[i].fork_right);
		printf("Puntero del tenedor izquierdo: %p\n", &p[i].fork_left);
		write(1, "\n", 1);
	}
}

static void	ft_thread_philos(t_philo *p, int n_philos)
{
	int	i;

	i = -1;
	while (++i < n_philos)
	{
		if (pthread_create(&p[i].tid, NULL, philo_rutine, &p[i]) != 0)
			ft_error("Thread error");
	}
}

static void	ft_thread_check_dead(t_args *args, t_philo *p)
{
	ft_check_dead(args, p);
}

static void	ft_join_threads(t_args *args, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		pthread_join(p[i++].tid, NULL);
	}
}

static void	ft_init_philosophers(t_vars *vars)
{
	t_args	*args;
	t_philo	*philo;

	args = &vars->args;
	philo = vars->philos;
	ft_thread_philos(philo, args->n_philo);
	ft_thread_check_dead(args, philo);
	ft_join_threads(args, philo);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	ft_check_ac(ac);
	ft_check_argv(av);
	ft_init_vars(&vars, av, ac);
	ft_init_philosophers(&vars);
	check(&vars);
}
