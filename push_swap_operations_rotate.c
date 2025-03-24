/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:38:59 by lposse            #+#    #+#             */
/*   Updated: 2025/03/24 20:17:29 by lposse           ###   ########.fr       */
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	ft_pushswap_rr(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*last;
	t_list	*first_b;
	t_list	*last_b;

	if ((!(*a) || (*a)->next) && (!(*b) || !(*b)->next))
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = (*a)->next;
	last->next = first;
	first->next = NULL;
	first_b = *b;
	last_b = *b;
	while (last_b->next != NULL)
		last_b = last_b->next;
	*b = first_b->next;
	last_b->next = first_b;
	first_b->next = NULL;
	write(1, "rr\n", 3);
}
