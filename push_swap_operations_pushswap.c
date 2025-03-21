/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_pushswap.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:39:49 by lposse            #+#    #+#             */
/*   Updated: 2025/03/21 18:52:01 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_sa(t_list **a)
{
	t_list	*temp;

	if (a && *a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
	return ;
}

void	ft_pushswap_sb(t_list **b)
{
	t_list	*temp;

	if (b && *b && (*b)->next)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = (*b)->next;
		(*b)->next = temp;
	}
	return ;
}

void	ft_pushswap_ss(t_list **a, t_list **b)
{
	ft_pushswap_sa(a);
	ft_pushswap_sb(b);
	return ;
}

void	ft_pushswap_pa(t_list **a, t_list **b)
{
	if (b && *b)
	{
		ft_lstadd_front(a, *b);
		ft_lstdel_first(b, del);
	}
}

void	ft_pushswap_pb(t_list **a, t_list **b)
{
	if (a && *a)
	{
		ft_lstadd_front(b, *a);
		ft_lstdel_first(a, del);
	}
}
