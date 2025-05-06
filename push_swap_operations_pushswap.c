/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_pushswap.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:39:49 by lposse            #+#    #+#             */
/*   Updated: 2025/05/06 21:23:41 by lposse           ###   ########.fr       */
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
		write(1, "sa\n", 3);
	}
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
		write(1, "sb\n", 3);
	}
}

void	ft_pushswap_ss(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp_b;

	if ((a && *a && (*a)->next) && (b && *b && (*b)->next))
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
		temp_b = *b;
		*b = (*b)->next;
		temp_b->next = (*b)->next;
		(*b)->next = temp_b;
		write(1, "ss\n", 3);
	}
}

void	ft_pushswap_pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_front(a, temp);
	write(1, "pa\n", 3);
}

void	ft_pushswap_pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp);
	write(1, "pb\n", 3);
}
