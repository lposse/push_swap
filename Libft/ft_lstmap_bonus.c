/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:25:43 by lposse            #+#    #+#             */
/*   Updated: 2025/03/20 20:24:55 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*error(t_list	*new_node, t_list *result, void (*del)(void *))
{
	t_list	*temp;

	if (new_node)
	{
		del(new_node->content);
		free(new_node);
	}
	while (result)
	{
		temp = result->next;
		del(result->content);
		free(result);
		result = temp;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_node;
	t_list	*last_node;

	result = NULL;
	last_node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
			return (error (new_node, result, del));
		new_node->content = f(lst->content);
		if (!(new_node->content))
			return (error (new_node, result, del));
		new_node->next = NULL;
		if (last_node)
			last_node->next = new_node;
		else
			result = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (result);
}
