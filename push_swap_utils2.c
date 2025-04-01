/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:30:19 by lposse            #+#    #+#             */
/*   Updated: 2025/04/01 21:56:55 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_lst_findcontent_byindex(t_list *a, int index)
{
	t_list	*temp;

	if (!a)
		return (NULL);
	temp = a;
	while (temp)
	{
		if (temp->index == index)
			return (temp->content);
		temp = temp->next;
	}
	return (NULL);
}

int	ft_pushswap_check_is_sorted(t_list *a)
{
	int	i;

	i = *(int *)(a->content);
	while (a)
	{
		if (i > *(int *)(a->content))
			return (0);
		i = *(int *)(a->content);
		a = a->next;
	}
	return (1);
}

void	ft_pushswap_freestack(t_list **a)
{
	t_list	*temp;

	if (!a)
		return ;
	while (*a)
	{
		temp = (*a)->next;
		(*a)->content = NULL;
		free(*a);
		*a = temp;
	}
}
