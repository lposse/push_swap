/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:29:23 by lposse            #+#    #+#             */
/*   Updated: 2025/05/06 21:19:49 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_position_in_b(t_list *b, int node_content)
{
	t_list	*temp;
	int		target_pos;
	int		max_index;

	if (!b)
		return (0);
	max_index = ft_lst_intmax_index(b);	
	if (node_content > ft_lst_intmax(b) || node_content < ft_lst_intmin(b))
		return ((max_index + 1) % ft_lstsize(b));
	temp = b;
	target_pos = 0;
	while (temp && temp->next)
	{
		if (node_content < *(int *)(temp->content) && node_content > *(int *)(temp->next->content))
			break;
		target_pos++;
		temp = temp->next;
	}
	return ((target_pos + 1) % ft_lstsize(b));
}
  
void	ft_rotate_stack_to_top(t_list **stack, int index, char stack_name)
{
	if (index < 0)
		index = ft_lstsize(*stack) - index;
	if (index <= ft_lstsize(*stack) / 2)
	{
		while (index-- > 0)
		{
			if (stack_name == 'a')
				ft_pushswap_ra(stack);
			if (stack_name == 'b')
				ft_pushswap_rb(stack);
		}
	}
	else
	{
		index = ft_lstsize(*stack) - index;
		while (index-- > 0)
		{
			if (stack_name == 'a')
				ft_pushswap_rra(stack);
			if (stack_name == 'b')
				ft_pushswap_rrb(stack);
		}
	}
}	

void	ft_pushswap_calculate_totalmoves2(int *moves_totop_a, int *moves_b, int *counter_rr_rrr)
{
	while (*moves_totop_a > 0 && *moves_b > 0)
	{
		(*counter_rr_rrr)++;
		(*moves_totop_a)--;
		(*moves_b)--;
	}
	while (*moves_totop_a < 0 && *moves_b < 0)
	{
		(*counter_rr_rrr)--;
		(*moves_totop_a)++;
		(*moves_b)++;
	}
}

int	ft_pushswap_calculate_totalmoves(t_list **a, t_list **b, int index_a, int *counter_rr_rrr)
{
	int	moves_totop_a;
	int	moves_b;
	int	node_content;
	int	target_pos_b;

	node_content = *(int *)ft_lst_findcontent_byindex(*a, index_a);
	moves_totop_a = calc_moves_to_top_a(*a, index_a);
	target_pos_b = find_target_position_in_b(*b, node_content);
	moves_b = calc_moves_to_position_b(*b, target_pos_b);
	*counter_rr_rrr = 0;
	ft_pushswap_calculate_totalmoves2(&moves_totop_a, &moves_b, counter_rr_rrr);
	return (ft_abs(moves_totop_a) + ft_abs(moves_b) + ft_abs(*counter_rr_rrr) + 1);
}

void	execute_optimal_moves(t_list **a, t_list **b, int index_node_a, int counter_rr_rrr)
{
	int	node_content;
	int	target_pos_b;
	
	node_content = *(int *)ft_lst_findcontent_byindex(*a, index_node_a);
	target_pos_b = find_target_position_in_b(*b, node_content);
	ft_pushswap_doublerotations(a, b, &index_node_a, &target_pos_b, &counter_rr_rrr);
	if (index_node_a != 0)
		ft_rotate_stack_to_top(a, index_node_a, 'a');
	if (target_pos_b != 0)
		ft_rotate_stack_to_top(b, target_pos_b, 'b');
	ft_pushswap_pb(a, b);
}
