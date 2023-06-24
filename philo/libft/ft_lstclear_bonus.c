/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:37:34 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/04 18:09:44 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		node = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = node;
	}
	*lst = NULL;
}
