/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_reverserotate.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:12:02 by lposse            #+#    #+#             */
/*   Updated: 2025/03/21 19:40:28 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_rra(t_list **a)
{
	t_list	*penultimo;
	t_list	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	penultimo = *a;
	while (penultimo->next != NULL && penultimo->next->next != NULL)
		penultimo = penultimo->next;
	last = penultimo->next;
	last->next = *a;
	penultimo->next = NULL;
	*a = last;
}

void	ft_pushswap_rrb(t_list **b)
{
	t_list	*penultimo;
	t_list	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	penultimo = *b;
	while (penultimo->next != NULL && penultimo->next->next != NULL)
		penultimo = penultimo->next;
	last = penultimo->next;
	last->next = *b;
	penultimo->next = NULL;
	*b = last;
}

void	ft_pushswap_rrr(t_list **a, t_list **b)
{
	ft_pushswap_rra(a);
	ft_pushswap_rrb(b);
}
