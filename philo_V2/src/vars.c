/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:20:57 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/21 19:45:07 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_init_argv(t_args *args, char **argv, int argc)
{
	args->n_philo = ft_atoi(argv[1]);
	args->tdie = ft_atoi(argv[2]);
	args->teat = ft_atoi(argv[3]);
	args->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->n_eats = ft_atoi(argv[5]);
	else
		args->n_eats = -1;
}
static void	ft_init_philos(t_args *args, t_philo *p)
{
	/*TODO*/
}

void	ft_init_vars(t_vars *vars, char **argv, int argc)
{
	ft_init_argv(&vars->args, argv, argc);
	vars->philos = malloc(sizeof(t_philo) * vars->args.n_philo);
	if (vars->philos == NULL)
		ft_error("Error malloc");
	ft_init_philos(&vars->args, &vars->philos);
}