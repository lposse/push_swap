/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:46:36 by lposse            #+#    #+#             */
/*   Updated: 2025/05/14 16:35:20 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_findnode_byindex(t_list *a, int index)
{
	t_list	*temp;

	if (!a)
		return (NULL);
	temp = a;
	ft_lstsize(a);
	while (temp)
	{
		if (temp->index == index)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	find_cheapest_element(t_list **a, t_list **b, int *cheapest, int *rr_rrr)
{
	int	position;
	int	min_moves;
	int	current_moves;
	int	best_rr_rrr;
	int	temp_rr_rrr;

	position = 0;
	min_moves = INT_MAX;
	*cheapest = 0;
	best_rr_rrr = 0;
	while (position < ft_lstsize(*a))
	{
		temp_rr_rrr = 0;
		current_moves = ft_calc_totalmoves(a, b, position, &temp_rr_rrr);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			*cheapest = position;
			best_rr_rrr = temp_rr_rrr;
		}
		position++;
	}
	*rr_rrr = best_rr_rrr;
	return (*cheapest);
}

int	find_target_position_in_a(t_list *a, int value)
{
	t_list	*temp;
	int		index;
	int		temp2;

	temp = a;
	index = 0;
	if (value > ft_lst_intmax(a) || value < ft_lst_intmin(a))
		return (ft_lst_intmin_index(a));
	while (temp && temp->next)
	{
		temp2 = *(int *)temp->next->content;
		if (value > *(int *)temp->content && value < temp2)
			return (index + 1);
		temp = temp->next;
		index++;
	}
	return (0);
}

void	ft_pushswap_algorithmturk2(t_list **a, t_list **b)
{
	int	cheapest_b;
	int	pos_push_a;
	int	node_content;
	int	rr_rrr;
	int	old_rr_rrr;

	while (*b && ft_lstsize(*b) > 0)
	{
		find_cheapest_element(b, a, &cheapest_b, &rr_rrr);
		node_content = *(int *)ft_lst_findcontent_byindex(*b, cheapest_b);
		pos_push_a = find_target_position_in_a(*a, node_content);
		old_rr_rrr = rr_rrr;
		ft_doublerotations(a, b, &pos_push_a, &rr_rrr);
		if (old_rr_rrr < 0)
			cheapest_b = cheapest_b + (ft_abs(old_rr_rrr) - ft_abs(rr_rrr));
		else
			cheapest_b = cheapest_b - (ft_abs(old_rr_rrr) - ft_abs(rr_rrr));
		if (cheapest_b != 0)
			ft_rotate_stack_to_top(b, cheapest_b, 'b');
		if (pos_push_a != 0)
			ft_rotate_stack_to_top(a, pos_push_a, 'a');
		ft_pushswap_pa(a, b);
	}
}

void	ft_pushswap_algorithmturk(t_list **a, t_list **b)
{
	int	cheapest_pos;
	int	counter_rr_rrr;
	int	b2;

	if (!a || !*a || ft_lstsize(*a) < 2 || ft_pushswap_check_is_sorted(a) == 1)
		return ;
	ft_pushswap_pb(a, b);
	ft_pushswap_pb(a, b);
	b2 = *(int *)(*b)->next->content;
	if (ft_lstsize(*b) == 2 && *(int *)(*b)->content < b2)
		ft_pushswap_sb(b);
	while (*a && ft_lstsize(*a) > 3)
	{
		find_cheapest_element(a, b, &cheapest_pos, &counter_rr_rrr);
		execute_optimal_moves(a, b, cheapest_pos, counter_rr_rrr);
	}
	ft_pushswap_algorithm3(a);
	ft_pushswap_algorithmturk2(a, b);
}
