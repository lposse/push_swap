/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:10:08 by lposse            #+#    #+#             */
/*   Updated: 2025/03/26 21:36:32 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_algorithm3(t_list **a)
{
	int	c2;
	int	c3;

	c2 = *(int *)((*a)->next->content);
	c3 = *(int *)((*a)->next->next->content);
	if ((*(int *)((*a)->content) < c2) && (*(int *)((*a)->content) < c3) && (c2 < c3))
		return ;
	if (*(int *)((*a)->content) > c2 && c2 < c3)
	{
		if (*(int *)((*a)->content) < c3)
			return (ft_pushswap_sa(a));
		if (*(int *)((*a)->content) > c3)
			return (ft_pushswap_ra(a));
	}
	if ((*(int *)((*a)->content) > c2) && (*(int *)((*a)->content) > c3) && (c2 > c3))
	{
		ft_pushswap_ra(a);
		return (ft_pushswap_sa(a));
	}
	if (*(int *)((*a)->content) < c2 && c2 > c3)
	{
		ft_pushswap_rra(a);
		if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
			return (ft_pushswap_sa(a));
	}
}

void	ft_pushswap_algorithm4_x1(t_list *a, t_list *b, int c1, int c3, int c4)
{
	if (c1 < c3 && c1 < c4)
	{
		if (c3 > c4)
		{
			ft_pushswap_pb(&a, &b);
			ft_pushswap_pb(&a, &b);
			ft_pushswap_ss(&a, &b);
			ft_pushswap_pa(&a, &b);
			return (ft_pushswap_pa(&a, &b));
		}
		return (ft_pushswap_sa(&a));
	}
	if (c3 < c4)
	{
		ft_pushswap_rra(&a);
		ft_pushswap_sa(&a);
		ft_pushswap_ra(&a);
		return (ft_pushswap_ra(&a));
	}
	if (c3 > c4)
	{
		ft_pushswap_sa(&a);
		ft_pushswap_rra(&a);
		return (ft_pushswap_sa(&a));
	}
}

void	ft_pushswap_algorithm4_4o3o2xxx(t_list *a, t_list *b, int c2, int c3, int c4)
{
	int	c1;

	c1 = *(int *)(a->content);
	if (c1 > c2 && c1 > c3 && c1 > c4)
	{
		ft_pushswap_pb(&a, &b);
		ft_pushswap_algorithm3(&a);
		ft_pushswap_pa(&a, &b);
		return (ft_pushswap_ra(&a));
	}
	if (c2 < c3 && c2 < c4)
		return (ft_pushswap_algorithm4_x1(a, b, c1, c3, c4));
	else
	{
		ft_pushswap_sa(&a);
		ft_pushswap_rra(&a);
		if (c4 > c3)
		{
			ft_pushswap_pb(&a, &b);
			ft_pushswap_rra(&a);
			ft_pushswap_pa(&a, &b);
			return ft_pushswap_ra(&a);
		}
		return ;
	}
}

void	ft_pushswap_algorithm4_x3o4xx(t_list *a, t_list *b, int c2, int c3, int c4)
{
	int	c1;

	c1 = *(int *)(a->content);
	if (c2 < c4)
	{
		ft_pushswap_ra(&a);
		ft_pushswap_ra(&a);
		ft_pushswap_pb(&a, &b);
		ft_pushswap_ra(&a);
		return (ft_pushswap_pa(&a, &b));
	}
	if (c1 > c3 && c1 > c4)
	{
		ft_pushswap_rra(&a);
		ft_pushswap_rra(&a);
		if (c3 > c4)
			return ft_pushswap_sa(&a);
		return ;
	}
	else
		return (ft_pushswap_algorithm4_pb3pa(a, b));	
}

void	ft_pushswap_algorithm4(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*fourth;
	int		c1;
	int		c2;
	int		c3;

	c1 = *(int *)((*a)->content);
	c2 = *(int *)((*a)->next->content);
	c3 = *(int *)((*a)->next->next->content);
	fourth = *a;
	while (fourth->next != NULL)
		fourth = fourth->next;
	temp = *a;
	while (c1 < *(int *)(temp->content) && temp->next != NULL)
		temp = temp->next;
	if (temp == fourth)
		return (ft_pushswap_algorithm4_pb3pa(*a, *b));
	if (temp == *a)
		return (ft_pushswap_algorithm4_4o3o2xxx(*a, *b, c2, c3, *(int *)(fourth->content)));
	if (temp == (*a)->next->next)
		return (ft_pushswap_rra(a));
	if (temp == (*a)->next)
		return (ft_pushswap_algorithm4_x3o4xx(*a, *b, c2, c3, *(int *)(fourth->content)));	
}
