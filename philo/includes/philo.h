/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:29:06 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/24 18:19:17 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/time.h>
# include "../libft/libft.h"

typedef struct s_args
{
	int	nb_phs;
	int	tdie;
	int	teat;
	int	tsleep;
	int	nb_eats;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				*is_dead;
	int				eaten;
	int				laps;
	long int		time_init;
	long int		time;
	int				tdie;
	int				teat;
	int				tsleep;
	pthread_t		tid;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	fork_left;
}			t_philo;

typedef struct s_vars
{
	t_args	args;
	t_philo	*philo;
}			t_vars;

// SRC
void	ft_init_vars(t_vars *v, char **args);
void	ft_init_threads(t_vars *v);
void	ft_init_philos(t_vars *v);
void	*rutine(void *vars);
// UTILS
int		ft_check_args(char **args);
void	ft_error(char *msg);
void	ft_put_msg(char *msg);
long int	ft_actual_time(void);
#endif