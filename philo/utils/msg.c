/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:10:58 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/01 15:46:42 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_put_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit (1);
}
/*
* 0 : NADA
* 1 : COMIDA
* 2 : DORMIR
* 3 : PENSAR
* 4 : MUERTE
*/
void	ft_philo_msg(char *msg, t_philo	*p, int	format)
{
	printf("[%6ld] ", (ft_actual_time() - p->time));
	if (format == 0)
		printf("\033[1;37m 🍴");
	else if(format == 1)
		printf("\033[1;33m 🍽️");
	else if(format == 2)
		printf("\033[1;34m 💤");
	else if(format == 3)
		printf("\033[1;32m 🤔");
	else if(format == 4)
		printf("\033[1;31m 💀");
	printf(" philo %d %s\n", p->id, msg);
	printf("\033[0m");
}
