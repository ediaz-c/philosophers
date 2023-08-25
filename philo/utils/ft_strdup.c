/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:44:08 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/08/25 18:01:53 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*cpy;

	str = (char *)s;
	i = ft_strlen(str) + 1;
	cpy = (char *)malloc (sizeof(char) * i);
	if (cpy == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
