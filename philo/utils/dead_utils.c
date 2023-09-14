/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:38:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/09/11 19:12:28 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_notify_philos(t_args *args, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		p[i].is_dead = 1;
	}
}
