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

void    ft_pushswap_algorithm4_pb3pa(t_list *a, t_list *b)
{
	ft_pushswap_pb(&a, &b);
	ft_pushswap_algorithm3(a);
	ft_pushswap_pa(&a, &b);
}

int	ft_pushswap_calculate_totalmoves(t_list *a, t_list *b, int index_a, int max_pos_b, int min_pos_b)
{
	int	moves_totop_a;
	int	moves_b;
	int	node_content;
	int	target_pos_b;

	node_content = *(int *)ft_lst_findcontent_byindex(a, index_a);
	moves_totop_a = calc_moves_to_top_a(a, index_a);
	target_pos_b = find_target_position_in_b(b, node_content, max_pos_b, min_pos_b);
	moves_b = calc_moves_to_position_b(b, target_pos_b);
	return (moves_totop_a + moves_b + 1);
}

int	find_cheapest_element(t_list *a, t_list *b, int *cheapest_pos)
{
	int	position;
	int	min_moves;
	int	current_moves;
	int	max_b;
	int	min_b;
    
	position = 0;
	min_moves = INT_MAX;
	*cheapest_pos = 0;
	max_b = ft_lst_intmax(b);
	min_b = ft_lst_intmin(b);
	while (position < ft_lstsize(a))
	{
		current_moves = ft_pushswap_calculate_totalmoves(a, b, position, max_b, min_b);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
	    		*cheapest_pos = position;
		}
		position++;
    	}
	return (min_moves);
}

void	ft_pushswap_algorithmturk(t_list **a, t_list **b)
{
	int	cheapest_pos;
	int	max_pos_b;
	int	min_pos_b;
	int	size_b;
	int	best_pos;

	ft_pushswap_pb(a, b);
	ft_pushswap_pb(a, b);
	if (ft_lstsize(*b) == 2 && ft_lst_findcontent_byindex(*b, 0) < ft_lst_findcontent_byindex(*b, 1))
		ft_pushswap_sb(b);
	while (ft_lstsize(*a) > 3)
	{
		max_pos_b = find_max_position(*b);
		min_pos_b = find_min_position(*b);
		find_cheapest_element(*a, *b, &cheapest_pos);
		execute_optimal_moves(a, b, cheapest_pos, max_pos_b, min_pos_b);
	}
	ft_pushswap_algorithm3(*a);
	while (ft_lstsize(*b) > 0)
	{
		best_pos = find_max_position(*b);
		size_b = ft_lstsize(*b);
		if (best_pos <= size_b / 2)
		{
			while (best_pos > 0)
			{
				ft_pushswap_rb(*b);
				best_pos--;
			}
		}
		else
		{
			while (best_pos < size_b)
			{
				ft_pushswap_rrb(*b);
				best_pos++;
				if (best_pos == size_b)
					best_pos = 0;
			}
		}
		ft_pushswap_pa(a, b);
	}
}
