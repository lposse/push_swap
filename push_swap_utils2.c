/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:30:19 by lposse            #+#    #+#             */
/*   Updated: 2025/04/01 21:56:55 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_lst_findcontent_byindex(t_list *a, int index)
{
	t_list	*temp;

	if (!a)
		return (NULL);
	temp = a;
	while (temp)
	{
		if (temp->index == index)
			return (temp->content);
		temp = temp->next;
	}
	return (NULL);
}

int	ft_pushswap_check_is_sorted(t_list *a)
{
	int	i;

	i = *(int *)(a->content);
	while (a)
	{
		if (i > *(int *)(a->content))
			return (0);
		i = *(int *)(a->content);
		a = a->next;
	}
	return (1);
}

void	ft_pushswap_freestack(t_list **a)
{
	t_list	*temp;

	if (!a)
		return ;
	while (*a)
	{
		temp = (*a)->next;
		(*a)->content = NULL;
		free(*a);
		*a = temp;
	}
}

int	ft_pushswap_findplace_pb(t_list *b, int num_to_pushb)
{
	t_list	*temp;
	int		i;

	if (num_to_pushb > *(int *)(b->content) && num_to_pushb < *(int *)(ft_lstlast(b)->content))
		return (0);
	if (num_to_pushb > ft_lst_intmax(b) || num_to_pushb < ft_lst_intmin(b))
		i = ft_lst_findindex_ofint(b, ft_lst_intmax(b));
	else
	{
		temp = b;
		i = 1;
		while (*(int *)(temp->content) < num_to_pushb || *(int *)(temp->next->content) > num_to_pushb)
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}

int	ft_pushswap_findplace_pa(t_list *a, int num_to_push)
{
	t_list	*temp;
	int		i;

	if (num_to_push < *(int *)(a->content) && num_to_push > *(int *)(ft_lstlast(a)->content))
		return (0);
	if (num_to_push > ft_lst_intmax(a) || num_to_push < ft_lst_intmin(a))
		i = ft_lst_findindex_ofint(a, ft_lst_intmin(a));
	else
	{
		temp = a;
		i = 1;
		while (*(int *)(temp->content) > num_to_push || *(int *)(temp->next->content) < num_to_push)
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}
