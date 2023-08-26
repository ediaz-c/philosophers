/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:22:41 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/26 11:14:58 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_msg(t_philo *p, char *msg, int action)
{
	if (ft_is_dead(p) && action != MORIR)
		return (0);
	pthread_mutex_lock(p->print);
	if (ft_is_dead(p) && action != MORIR)
	{
		pthread_mutex_unlock(p->print);
		return (0);
	}
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
	if (ft_is_dead(p))
		return (0);
	return (1);
}

void	ft_unlock_all(t_philo *p)
{
	pthread_mutex_unlock(&p->fork_left);
	if (p->fork_right != NULL)
		pthread_mutex_unlock(p->fork_right);
}

void	ft_wait_to_eat(t_philo *p)
{
	if (!p->first_to_eat)
		usleep(500);
}

void	ft_all_zero(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
		args->id_finish[i] = 0;
}
