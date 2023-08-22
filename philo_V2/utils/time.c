/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:20:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/22 16:23:30 by ediaz--c         ###   ########.fr       */
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