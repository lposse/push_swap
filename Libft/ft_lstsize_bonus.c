/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:18:10 by lposse            #+#    #+#             */
/*   Updated: 2025/03/26 19:14:28 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	int		index;
	t_list	*ptr;

	count = 0;
	index = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr->index = index;
		index++;
		ptr = ptr->next;
	}
	return (count);
}
