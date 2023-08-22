/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:32:51 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/21 19:33:54 by ediaz--c         ###   ########.fr       */
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
	int				first_eat;
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
/** init.c **/
void	ft_init_vars(t_vars *vars, char **argv, int argc);

/* UTILS */
/** error.c **/
/**Imprime un mensaje de error y sale con un "exit(1)"**/
void	ft_error(char *error);
void	ft_puterror_str(char *error, char *arg, int is_free);
/** arguments.c **/
void	ft_check_ac(int num_args);
void	ft_check_argv(char **args);

#endif