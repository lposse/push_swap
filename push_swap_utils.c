/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:37:27 by lposse            #+#    #+#             */
/*   Updated: 2025/03/26 21:34:35 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_findindex_ofint(t_list *a, int c)
{
	int		i;
	t_list	*temp;

	if (!a)
		return (-1);
	temp = a;
	i = 0;
	while (temp)
	{
		if (*(int *)(temp->content) == c)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

int	ft_lst_intmin(t_list *a)
{
	int		min;
	t_list	*temp;

	if (a == NULL)
		return (0);
	temp = a->next;
	min = *(int *)(a->content);
	while (temp)
	{
		if (min > *(int *)(temp->content))
			min = *(int *)(temp->content);
		temp = temp->next;
	}
	return (min);
}

int	ft_lst_intmin_index(t_list *a)
{
	int	min;
	int	index;

	min = ft_lst_intmin(a);
	index = ft_lst_findindex_ofint(a, min);
	return (index);
}

int	ft_lst_intmax(t_list *a)
{
	int		max;
	t_list	*temp;

	if (a == NULL)
		return (0);
	temp = a->next;
	max = *(int *)(a->content);
	while (temp)
	{
		if (max < *(int *)(temp->content))
			max = *(int *)(temp->content);
		temp = temp->next;
	}
	return (max);
}

int	ft_lst_intmax_index(t_list *a)
{
	int	max;
	int	index;

	max = ft_lst_intmax(a);
	index = ft_lst_findindex_ofint(a, max);
	return (index);
}
