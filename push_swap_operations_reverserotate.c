/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_reverserotate.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:12:02 by lposse            #+#    #+#             */
/*   Updated: 2025/03/24 20:25:45 by lposse           ###   ########.fr       */
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	ft_pushswap_rrr(t_list **a, t_list **b)
{
	t_list	*penultimo;
	t_list	*last;
	t_list	*penultimo_b;
	t_list	*last_b;

	if ((!a || !(*a) || !(*a)->next) && (!b || !(*b) || !(*b)->next))
		return ;
	penultimo = *a;
	while (penultimo->next != NULL && penultimo->next->next != NULL)
		penultimo = penultimo->next;
	last = penultimo->next;
	last->next = *a;
	penultimo->next = NULL;
	*a = last;
	penultimo_b = *b;
	while (penultimo_b->next != NULL && penultimo_b->next->next != NULL)
		penultimo_b = penultimo_b->next;
	last_b = penultimo_b->next;
	last_b->next = *b;
	penultimo_b->next = NULL;
	*b = last_b;
	write(1, "rrr\n", 4);
}
