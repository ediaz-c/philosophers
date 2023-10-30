/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:36:48 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/30 21:46:48 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	return (0);
}

int	ft_puterror_arg(char *error, char *arg, int is_free)
{
	printf(RED"%s:"OFF" %s\n", error, arg);
	if (is_free)
		free(arg);
	return (0);
}
