/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:34:46 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/10/31 09:14:19 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
		return (ft_error("Mutex error"));
	return (1);
}

pthread_mutex_t	*ft_create_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (mutex == NULL)
		return (ft_error("Error alocando mutex"), NULL);
	return (mutex);
}

void	ft_mod_int_values(t_philo *p, int *tochange, int value)
{
	pthread_mutex_lock(p->mod);
	*tochange = value;
	pthread_mutex_unlock(p->mod);
}

void	ft_mod_long_values(t_philo *p, long int *tochange, long int value)
{
	pthread_mutex_lock(p->mod);
	*tochange = value;
	pthread_mutex_unlock(p->mod);
}
