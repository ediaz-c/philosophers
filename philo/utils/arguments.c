/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:32:31 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/30 21:47:08 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_ac(int num_args)
{
	if (num_args == 1)
	{
		printf("./philo [number_of_philosophers] [time_to_die] \
	[time_to_eat] [time_to_sleep] [number_eats]\n");
		return (0);
	}
	else if (num_args != 5 && num_args != 6)
		return(ft_error("Numero de argumentos invalidos"));
	return (1);
}

static int	ft_limits_number(char *number)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (number[i])
	{
		nb = (nb * 10) + (number[i] - '0');
		i++;
	}
	if (nb > INT_MAX || nb <= 0)
		return (0);
	return (1);
}

static int	ft_is_valid_number(char *number)
{
	int		i;

	i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i++]) == 0)
			return (0);
	}
	if (!ft_limits_number(number))
		ft_puterror_arg("Numero fuera de los limites", number, 0);
	return (1);
}

int	ft_check_argv(char **args)
{
	char	*n_tmp;
	int		i;

	i = 0;
	while (args[++i])
	{
		n_tmp = ft_strtrim(args[i], " \t\n");
		if (!ft_is_valid_number(n_tmp))
			return (ft_puterror_arg("Argumento invalido", n_tmp, 1));
		free(n_tmp);
	}
	return (1);
}
