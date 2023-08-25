/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:20:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/22 20:20:13 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	ft_actual_time(void)
{
	long int		time;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
		ft_error("Time error");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

long int	ft_timer(t_philo *p)
{
	return (ft_actual_time() - p->time);
}