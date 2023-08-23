/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:34:46 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 12:15:51 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
		ft_error("Mutex error");
}

pthread_mutex_t	*ft_create_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (mutex == NULL)
		ft_error("Error alocando mutex");
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
