/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:10:58 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/07/01 20:03:09 by ediaz--c         ###   ########.fr       */
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
* 0 : FORK LEFT
* 1 : FORK RIGHT
* 2 : COMIDA
* 3 : DORMIR
* 4 : PENSAR
* 5 : MUERTE
*/
void	ft_philo_msg(t_philo *p, int format)
{
	if (format == 0)
		printf("\033[1;37m[%6ld] 🍴 philo %d take right fork\n\033[0m",
			(ft_actual_time() - p->time), p->id);
	else if (format == 1)
		printf("\033[1;37m[%6ld] 🍴 philo %d take left fork\n\033[0m",
			(ft_actual_time() - p->time), p->id);
	else if (format == 2)
		printf("\033[1;33m[%6ld] 🍽️ philo %d is eating\n\033[0m",
			(ft_actual_time() - p->time), p->id);
	else if (format == 3)
		printf("\033[1;34m[%6ld] 💤 philo %d is sleeping\n\033[0m",
			(ft_actual_time() - p->time), p->id);
	else if (format == 4)
		printf("\033[1;32m[%6ld] 🤔 philo %d is thinking\n\033[0m",
			(ft_actual_time() - p->time), p->id);
	else if (format == 5)
		printf("\033[1;31m[%6ld] 💀 philo %d is dead\n\033[0m",
			(ft_actual_time() - p->time), p->id);
}
