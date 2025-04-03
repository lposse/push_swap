/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:29:23 by lposse            #+#    #+#             */
/*   Updated: 2025/04/01 21:20:22 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves_to_top_a(t_list *a, int element_index)
{
	int	stack_size;

	stack_size = ft_lstsize(a);
	if (element_index <= stack_size / 2)
		return (element_index);
	else
		return (element_index - stack_size);
}

int	calc_moves_to_position_b(t_list *b, int target_pos)
{
	int	size_b;

	if (!b)
		return (0);
	size_b = ft_lstsize(b);
	if (target_pos <= size_b / 2)
		return (target_pos);
	else
		return (target_pos - size_b);
}

int	find_target_position_in_b(t_list *b, int node_content, int max_index, int min_index)
{
	t_list	*temp;
	int		target_pos;

	if (!b)
		return (0);
	if (node_content > *(int *)ft_lst_findcontent_byindex(b, max_index))
		return (max_index);
	if (node_content < *(int *)ft_lst_findcontent_byindex(b, min_index))
		return (max_index);
	temp = b;
	target_pos = 0;
	while (temp)
	{
		if (temp->next && node_content < *(int *)(temp->content) && node_content > *(int *)(temp->next->content))
		{
			target_pos++;
			break;
		}
		temp = temp->next;
		target_pos++;
	}
	return (target_pos);
}

int	ft_pushswap_calculate_totalmoves(t_list *a, t_list *b, int index_a, int max_pos_b, int min_pos_b)
{
	int	moves_totop_a;
	int	moves_b;
	int	node_content;
	int	target_pos_b;
	int	counter_rr_rrr;

	node_content = *(int *)ft_lst_findcontent_byindex(a, index_a);
	moves_totop_a = calc_moves_to_top_a(a, index_a);
	target_pos_b = find_target_position_in_b(b, node_content, max_pos_b, min_pos_b);
	moves_b = calc_moves_to_position_b(b, target_pos_b);
	counter_rr_rrr = 0;
	while (moves_totop_a > 0 && moves_b > 0)
	{
		counter_rr_rrr++;
		moves_totop_a--;
		moves_b--;
	}
	while (moves_totop_a < 0 && moves_b < 0)
	{
		counter_rr_rrr++;
		moves_totop_a++;
		moves_b++;
	}
	if (moves_totop_a < 0)
		moves_totop_a = -(moves_totop_a);
	if (moves_b < 0)
		moves_b = -(moves_b);
	return (moves_totop_a + moves_b + counter_rr_rrr + 1);
}

void	execute_optimal_moves(t_list **a, t_list **b, int index_node_a, int max_index_b, int min_index_b)
{
	int	node_content;
	int	target_pos_b;
	int	a_size;
	int	b_size;

	a_size = ft_lstsize(*a);
	b_size = ft_lstsize(*b);
	node_content = *(int *)ft_lst_findcontent_byindex(*a, index_node_a);
	target_pos_b = find_target_position_in_b(*b, node_content, max_index_b, min_index_b);
	while (index_node_a > 0)
	{
		if (index_node_a <= a_size / 2)
		{
			ft_pushswap_ra(a);
			index_node_a--;
		}
		else
		{
			ft_pushswap_rra(a);
			index_node_a = (index_node_a + 1) % a_size;
		}
	}
	while (target_pos_b > 0)
	{
		if (target_pos_b <= b_size / 2)
		{
			ft_pushswap_rb(b);
			target_pos_b--;
		}
		else
		{
			ft_pushswap_rrb(b);
			target_pos_b = (target_pos_b + 1) % b_size;
		}
	}
	ft_pushswap_pb(a, b);
}
