/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:33:02 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/06/23 17:55:58 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isnumber(char *number)
{
	int	i;

    i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i++]) == 0)
			return (0);
	}
	return (1);
}

int	ft_is_valid_number(char *number)
{
	int	i;
	long	nb;

	i = 0;
	nb = 0;
	while (number[i] >= '0' && number[i] <= '9')
	{
		nb = (nb * 10) + (number[i] - '0');
		i++;
	}
	if (nb > INT_MAX || nb <= 0)
		return (0);
	return (nb);
}

int	ft_check_args(char **args)
{
	char	*tmp;
	int		i;

	i = 0;
	while (args[++i])
	{
		tmp = ft_strtrim(args[i], " \t\n");
		if (ft_isnumber(tmp))
		{
			if (ft_is_valid_number(tmp) == 0)
				break ;
		}
		free(tmp);
	}
	if (args[i] == NULL)
		return (1);
	return (0);
}
