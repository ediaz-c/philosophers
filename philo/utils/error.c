/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:36:48 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/22 18:45:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(1);
}

void	ft_puterror_arg(char *error, char *arg, int is_free)
{
	printf(RED"%s:"OFF" %s\n", error, arg);
	if (is_free)
		free(arg);
	exit (1);
}