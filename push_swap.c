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

void	ft_pushswap_algorithm3(t_list *a)
{
	int	c2;
	int	c3;

	c2 = (int *)(a->next->content);
	c3 = (int *)(a->next->next->content);
	if (((int *)(a->content) < c2) && ((int *)(a->content) < c3) && (c2 < c3))
		return ;
	if ((int *)(a->content) > c2 && c2 < c3)
	{
		if ((int *)(a->content) < c3)
			return (ft_pushswap_sa(a));
		if ((int *)(a->content) > c3)
			return (ft_pushsap_ra(a));
	}
	if (((int *)(a->content) > c2) && ((int *)(a->content) > c3) && (c2 > c3))
	{
		ft_pushswap_ra(a);
		return (ft_pushswap_sa(a));
	}
	if ((int *)(a->content) < c2 && c2 > c3)
	{
		ft_pushswap_rra(a);
		if ((int *)(a->content) < c3)
			return (ft_pushswap_sa(a));
	}
}

void	ft_pushswap_algorithm4(t_list *a, t_list *b)
{
	t_list	*temp;
	t_list	*fourth;
	int		c1;
	int		c2;
	int		c3;

	c1 = (int *)(a->content);
	c2 = (int *)(a->next->content);
	c3 = (int *)(a->next->next->content);
	fourth = a;
	while (fourth->next != NULL)
		fourth = fourth->next;
	temp = a;
	while (c1 < *(int *)(temp->content) && temp->next != NULL)
		temp = temp->next;
	if (temp == fourth)
	{
		ft_pushswap_pb(a, b);
		ft_pushswap_algorithm3(a);
		return (ft_pushswap_pa(a, b));
	}
	if (temp == a)
	{
		if (c1 > c2 && c1 > c3 && c1 > *(int *)(fourth->content))
		{
			ft_pushswap_pb(a, b);
			ft_pushswap_algorithm3(a);
			ft_pushswap_pa(a, b);
			return (ft_pushswap_ra(a));
		}
	}
}
