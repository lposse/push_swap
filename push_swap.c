/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:10:08 by lposse            #+#    #+#             */
/*   Updated: 2025/03/24 22:24:40 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_algorithm2(t_list *a)
{
	if (*(int *)(a->content) > *(int *)(a->next->content))
		ft_pushswap_sa(a);
}

void	ft_pushswap_algorithm4(t_list *a, t_list *b)
{
}
