/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:22:41 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 16:42:24 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_msg(t_philo *p, char *msg, int action)
{
	pthread_mutex_lock(p->print);
	if (action == LEFT)
		printf(BWHITE"[%ld] Philo %d %s\n"OFF, ft_timer(p), p->id, msg);
	else if (action == RIGHT)
		printf(BWHITE"[%ld] Philo %d %s\n"OFF, ft_timer(p), p->id, msg);
	else if (action == COMER)
		printf(BYELLOW"[%ld] Philo %d %s\n"OFF, ft_timer(p), p->id, msg);
	else if (action == DORMIR)
		printf(BBLUE"[%ld] Philo %d %s\n"OFF, ft_timer(p), p->id, msg);
	else if (action == PENSAR)
		printf(BGREEN"[%ld] Philo %d %s\n"OFF, ft_timer(p), p->id, msg);
	else if (action == MORIR)
		printf(BRED"[%ld] Philo %d %s\n"OFF, ft_timer(p), p->id, msg);
	pthread_mutex_unlock(p->print);
}

void	ft_unlock_all(t_philo *p)
{
	pthread_mutex_unlock(&p->fork_left);
	if (p->fork_right != NULL)
		pthread_mutex_unlock(p->fork_right);
}