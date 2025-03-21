/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:38:59 by lposse            #+#    #+#             */
/*   Updated: 2025/03/21 18:51:02 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_ra(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = (*a)->next;
	last->next = first;
	first->next = NULL;
}

void	ft_pushswap_rb(t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	last->next = first;
	first->next = NULL;
}

void	ft_pushswap_rr(t_list **a, t_list **b)
{
	ft_pushswap_ra(a);
	ft_pushswap_rb(b);
}
