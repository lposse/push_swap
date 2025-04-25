/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:01:31 by lposse            #+#    #+#             */
/*   Updated: 2025/04/01 21:56:08 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_algorithm2(t_list **a)
{
	if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
		ft_pushswap_sa(a);
}

void	ft_pushswap_prealgorithm(int list_size, t_list **a, t_list **b)
{
	if (list_size == 2)
		return (ft_pushswap_algorithm2(a));
	if (list_size == 3)
		return (ft_pushswap_algorithm3(a));
	/* if (list_size == 4)
		return (ft_pushswap_algorithm4(a, b));*/
	if (list_size >= 4)
		return (ft_pushswap_algorithmturk(a, b));
}

int	ft_is_positive_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_pushswap_error(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (ft_is_positive_int(argv[i]) == 0 || ft_atoi(argv[i]) >= INT_MAX)
		{
			write (2, "Error\n", 6);
			return (1);
		}
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write (2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		atoi;
	t_list	*a;
	t_list	*b;
	t_list	*new_node;

	a = NULL;
	b = NULL;
	if (argc <= 1 || ft_pushswap_error(argv + 1) == 1)
		return (1);
	atoi = ft_atoi(argv[1]);
	if (argc > 1)
		a = ft_lstnew(ft_memcpy(malloc(sizeof(int)), &atoi, sizeof(int)));
	if (!a)
	{
		ft_pushswap_freestack(&a, &b);
		return (1);
	}
	i = 2;
	while (argv[i])
	{
		atoi = ft_atoi(argv[i]);
		new_node = ft_lstnew(ft_memcpy(malloc(sizeof(int)), &atoi, sizeof(int)));
		if (!new_node)
		{
			ft_pushswap_freestack(&a, &b);
			return (1);
		}
		ft_lstadd_back(&a, new_node);
		i++;
	}
	i = ft_lstsize(a);
	ft_pushswap_prealgorithm(i, &a, &b);
	ft_pushswap_finalcheck(&a, &b);
	return (0);
}
