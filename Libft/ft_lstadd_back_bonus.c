/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:27:08 by lposse            #+#    #+#             */
/*   Updated: 2025/01/13 21:34:55 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstlast13(t_list *lst)
{
	t_list	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ultimo_nodo;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ultimo_nodo = ft_lstlast13(*lst);
	ultimo_nodo->next = new;
	new->next = NULL;
}
