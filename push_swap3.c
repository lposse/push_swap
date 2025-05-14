/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:29:23 by lposse            #+#    #+#             */
/*   Updated: 2025/05/14 16:35:40 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_position_in_b(t_list *b, int node_content)
{
	t_list	*temp;
	int		target_pos;
	int		max_index;
	int		temp2;

	if (!b)
		return (0);
	max_index = ft_lst_intmax_index(b);
	if (node_content > ft_lst_intmax(b) || node_content < ft_lst_intmin(b))
		return ((max_index + 1) % ft_lstsize(b));
	temp = b;
	target_pos = 0;
	while (temp && temp->next)
	{
		temp2 = *(int *)(temp->next->content);
		if (node_content < *(int *)(temp->content) && node_content > temp2)
			break ;
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

void	ft_calc_totalmoves2(int *moves_totop_a, int *moves_b, int *c_rr_rrr)
{
	while (*moves_totop_a > 0 && *moves_b > 0)
	{
		(*c_rr_rrr)++;
		(*moves_totop_a)--;
		(*moves_b)--;
	}
	while (*moves_totop_a < 0 && *moves_b < 0)
	{
		(*c_rr_rrr)--;
		(*moves_totop_a)++;
		(*moves_b)++;
	}
}

int	ft_calc_totalmoves(t_list **a, t_list **b, int index_a, int *rr_rrr)
{
	int	moves_totop_a;
	int	moves_b;
	int	node_content;
	int	target_pos_b;

	node_content = *(int *)ft_lst_findcontent_byindex(*a, index_a);
	moves_totop_a = calc_moves_to_top_a(*a, index_a);
	target_pos_b = find_target_position_in_b(*b, node_content);
	moves_b = calc_moves_to_position_b(*b, target_pos_b);
	*rr_rrr = 0;
	ft_calc_totalmoves2(&moves_totop_a, &moves_b, rr_rrr);
	return (ft_abs(moves_totop_a) + ft_abs(moves_b) + ft_abs(*rr_rrr) + 1);
}

void	execute_optimal_moves(t_list **a, t_list **b, int index_a, int rr_rrr)
{
	int	node_content;
	int	target_pos_b;
	int	old_rr_rrr;

	node_content = *(int *)ft_lst_findcontent_byindex(*a, index_a);
	target_pos_b = find_target_position_in_b(*b, node_content);
	old_rr_rrr = rr_rrr;
	ft_doublerotations(a, b, &index_a, &rr_rrr);
	if (old_rr_rrr < 0)
		target_pos_b = target_pos_b + (ft_abs(old_rr_rrr) - ft_abs(rr_rrr));
	else
		target_pos_b = target_pos_b - (ft_abs(old_rr_rrr) - ft_abs(rr_rrr));
	if (index_a != 0)
		ft_rotate_stack_to_top(a, index_a, 'a');
	if (target_pos_b != 0)
		ft_rotate_stack_to_top(b, target_pos_b, 'b');
	ft_pushswap_pb(a, b);
}
