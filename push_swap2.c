/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:46:36 by lposse            #+#    #+#             */
/*   Updated: 2025/04/01 21:54:44 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_findnode_byindex(t_list *a, int index)
{
	t_list *temp;

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
	
int	find_cheapest_element(t_list **a, t_list **b, int *cheapest_pos, int *counter_rr_rrr)
{
	int	position;
	int	min_moves;
	int	current_moves;
    
	position = 0;
	min_moves = INT_MAX;
	*cheapest_pos = 0;
	while (position < ft_lstsize(*a))
	{
		current_moves = ft_pushswap_calculate_totalmoves(a, b, position, counter_rr_rrr);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
	    		*cheapest_pos = position;
		}
		position++;
    	}
	return (*cheapest_pos);
}

int	find_target_position_in_a(t_list *a, int value)
{
	t_list	*temp;
	int		index;

	temp = a;
	index = 0;
	if (value > ft_lst_intmax(a) || value < ft_lst_intmin(a))
		return (ft_lst_intmin_index(a));
	while (temp && temp->next)
	{
		if (value > *(int *)temp->content && value < *(int *)temp->next->content)
			return (index + 1);
		temp = temp->next;
		index++;
	}
	return (0);
}

void	ft_pushswap_algorithmturk2(t_list **a, t_list **b)
{
	int	pos_max_b;
	int	pos_push_a;

	while (*b && ft_lstsize(*b) > 0)
	{
		pos_max_b = ft_lst_intmax_index(*b);
		if (pos_max_b != 0)
			ft_rotate_stack_to_top(b, pos_max_b, 'b');
		pos_push_a = find_target_position_in_a(*a, *(int *)(*b)->content);
		if (pos_push_a != 0)
			ft_rotate_stack_to_top(a, pos_push_a, 'a');
		ft_pushswap_pa(a, b);
	}
}

void	ft_pushswap_algorithmturk(t_list **a, t_list **b)
{
	int	cheapest_pos;
	int	counter_rr_rrr;

	if (!a || !*a || ft_lstsize(*a) < 2 || ft_pushswap_check_is_sorted(a) == 1)
		return ;
	ft_pushswap_pb(a, b);
	ft_pushswap_pb(a, b);
	if (ft_lstsize(*b) == 2 && *(int *)ft_lst_findcontent_byindex(*b, 0) < *(int *)ft_lst_findcontent_byindex(*b, 1))
		ft_pushswap_sb(b);
	while (*a && ft_lstsize(*a) > 3)
	{
		find_cheapest_element(a, b, &cheapest_pos, &counter_rr_rrr);
		execute_optimal_moves(a, b, cheapest_pos, counter_rr_rrr);
	}
	ft_pushswap_algorithm3(a);
	ft_pushswap_algorithmturk2(a, b);
}
