/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:32:51 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/23 12:18:46 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define RED "\033[0;31m"
# define OFF "\033[0m"
# define BRED "\033[1;31m"
# define BWHITE "\033[1;37m"
# define BYELLOW "\033[1;33m"
# define BGREEN "\033[1;32m"
# define BBLUE "\033[1;34m"
# define LEFT 1
# define RIGHT 2
# define COMER 3
# define DORMIR 4
# define PENSAR 5
# define MORIR 6
# define UNLIMITED -1

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/includes/libft.h"

typedef struct s_args
{
	int			n_philo;
	int			tdie;
	int			teat;
	int			tsleep;
	int			n_eats;
	long int	time_init;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	long int		last_eat;
	int				laps;
	int				first_to_eat;
	int				n_eats;
	long int		time;
	int				tdie;
	int				teat;
	int				tsleep;
	pthread_t		tid;
	pthread_mutex_t	*mod;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	fork_left;
}	t_philo;

typedef struct s_vars
{
	t_args args;
	t_philo *philos;
}	t_vars;

/* SRC */
/** vars.c **/
void			ft_init_vars(t_vars *vars, char **argv, int argc);
/** rutine.c **/
void			*philo_rutine(void *philo);
int				ft_is_dead(t_philo *p);
/** actions.c **/
int				ft_take_forks(t_philo *p);
int 			ft_drop_forks(t_philo *p);
int				ft_eat(t_philo *p);
int				ft_sleep(t_philo *p);
int				ft_think(t_philo *p);
/** dead.c **/
void	ft_check_dead(t_args *args, t_philo *p);
/* UTILS */
/** error.c **/
/**Imprime un mensaje de error y sale con un "exit(1)"**/
void			ft_error(char *error);
void			ft_puterror_arg(char *error, char *arg, int is_free);
/** arguments.c **/
void			ft_check_ac(int num_args);
void			ft_check_argv(char **args);
/** time.c **/
long int		ft_actual_time(void);
long int		ft_timer(t_philo *p);
/** mutex.c **/
void			ft_init_mutex(pthread_mutex_t *mutex);
pthread_mutex_t	*ft_create_mutex(void);
void			ft_mod_int_values(t_philo *p, int *tochange, int value);
void			ft_mod_long_values(t_philo *p, long int *tochange, long int value);
/** philos_utils.c **/
/**
Action:
- 1: Tenedor izquierdo
- 2: Tenedor derecho
- 3: Comer
- 4: Dormir
- 5: Pensar
- 6: Muerte
**/
void			ft_philo_msg(t_philo *p, char *msg, int action);
int				ft_philo_alone(t_philo *p);
void			ft_unlock_all(t_philo *p);
/** dead_utils.c **/
void	ft_notify_philos(t_args *args, t_philo *p);
#endif