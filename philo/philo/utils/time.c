/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:44:30 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/23 20:04:44 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	ft_actual_time(void)
{
	long int		time;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0) 
		ft_error("time error");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	printf("SEC: %ld\nMILISEC: %d\n", current_time.tv_sec * 1000, current_time.tv_usec/1000);
	printf("%ld\n", time);
	return (time);
}
