/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:03:43 by lposse            #+#    #+#             */
/*   Updated: 2025/05/06 21:04:08 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	find_max_closest_to_top(t_list *b)
{
	int		max_val;
	int		i;
	t_list	*tmp;

	max_val = ft_lst_intmax(b);
	i = 0;
	tmp = b;
	while (tmp)
	{
		if (*(int *)tmp->content == max_val)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
