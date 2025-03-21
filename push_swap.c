/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:01:31 by lposse            #+#    #+#             */
/*   Updated: 2025/03/21 20:24:38 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_algorithm2(t_list *a)
{
	t_list	segundo;

	segundo = a->next;
	if ((a->content) > (segundo->content))
		return (ft_pushswap_sa(a));
}

void	ft_pushswap_algorithm3(t_list *a, t_list *b)
{
	int	*content;

	1 2 3
	o content de nodo 1 > content de nodo 2
}

void	ft_pushswap_algorithm4(t_list *a, t_list *b)
{

}

void	ft_pushswap_prealgorithm(int list_size, t_list **a, t_list **b)
{
	if (list_size == 2)
		return (ft_pushswap_algorithm2(a));
	if (list_size == 3)
		return (ft_pushswap_algorithm3(a, b));
	if (list_size == 4)
		return (ft_pushswap_algorithm4(a, b));
}

int	ft_pushswap_error()
{
	while (argv[i])
	{
		if (argv[i] == argv[i + 1])
			ERROR;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int	list_size;
	t_list		*a;
	t_list		*b;
	t_list		*new_node;

	if (ft_pushswap_error(argv + 1) == 1)
		return (1);
	b = ft_lstnew(NULL);
	a = NULL;
	if (argc > 1)
		a = ft_lstnew((void *)(long)ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		new_node = ft_lstnew((void *)(long)ft_atoi(argv[i]));
		ft_lstadd_back(&a, new_node);
		i++;
	}
	list_size = ft_lstsize(a);
	ft_pushswap_prealgorithm(list_size, &a, &b);
	return (0);
}
