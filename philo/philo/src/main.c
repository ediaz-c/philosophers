/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:29:33 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/19 19:11:43 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	if (ac != 7 && ac != 6)
		printf("Numero de argumentos invalidos\n");
	if (ft_check_args(av) == 0)
		printf("Argumento invalido\n");
}