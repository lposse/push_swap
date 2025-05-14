/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:10:08 by lposse            #+#    #+#             */
/*   Updated: 2025/05/14 16:35:00 by lposse           ###   ########.fr       */
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

void	ft_doublerotations(t_list **a, t_list **b, int *idx_a, int *rr_rrr)
{
	while (*rr_rrr > 0)
	{
		ft_pushswap_rr(a, b);
		(*rr_rrr)--;
		(*idx_a)--;
	}
	while (*rr_rrr < 0)
	{
		ft_pushswap_rrr(a, b);
		(*rr_rrr)++;
		(*idx_a)++;
	}
}

int	ft_pushswap_finalcheck(t_list **a, t_list **b)
{
	int	min_index;

	if (ft_pushswap_check_is_sorted(a) == 0)
	{
		min_index = ft_lst_findindex_ofint(*a, ft_lst_intmin(*a));
		if (min_index != 0)
		{
			if (min_index <= ft_lstsize(*a) / 2)
				while (min_index-- > 0)
					ft_pushswap_ra(a);
			else
			{
				min_index = ft_lstsize(*a) - min_index;
				while (min_index-- > 0)
					ft_pushswap_rra(a);
			}
		}
	}
	ft_pushswap_freestack(a, b);
	return (0);
}

void	ft_pushswap_algorithm3(t_list **a)
{
	int	s;
	int	t;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	s = *(int *)((*a)->next->content);
	t = *(int *)((*a)->next->next->content);
	if (*(int *)((*a)->content) < s && (*(int *)((*a)->content) < t) && (s < t))
		return ;
	if (*(int *)((*a)->content) > s && s < t && *(int *)((*a)->content) < t)
		ft_pushswap_sa(a);
	else if (*(int *)((*a)->content) > s && s > t)
	{
		ft_pushswap_sa(a);
		ft_pushswap_rra(a);
	}
	else if (*(int *)(*a)->content > s && s < t && *(int *)(*a)->content > t)
		ft_pushswap_ra(a);
	else if (*(int *)(*a)->content < s && s > t && *(int *)(*a)->content < t)
	{
		ft_pushswap_sa(a);
		ft_pushswap_ra(a);
	}
	else if (*(int *)(*a)->content < s && s > t && *(int *)(*a)->content > t)
		ft_pushswap_rra(a);
}
