/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:10:58 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/30 19:34:37 by ediaz--c         ###   ########.fr       */
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

void	ft_philo_msg(char *msg, t_philo	*p)
{
	printf("[%6ld] philo %d %s\n", (ft_actual_time() - p->time), p->id, msg);
}
