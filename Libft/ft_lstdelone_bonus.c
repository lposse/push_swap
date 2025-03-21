/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:38:33 by lposse            #+#    #+#             */
/*   Updated: 2025/03/21 18:49:14 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_first(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(temp, del);
	return ;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
