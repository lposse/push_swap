/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:01:31 by lposse            #+#    #+#             */
/*   Updated: 2025/05/14 14:17:08 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_positive_int(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_pushswap_prealgorithm(int list_size, t_list **a, t_list **b)
{
	int	index_push_a;

	if (ft_pushswap_check_is_sorted(a) == 1)
		return ;
	if (list_size == 2)
	{
		if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
			return (ft_pushswap_sa(a));
		return ;
	}
	if (list_size == 3)
		return (ft_pushswap_algorithm3(a));
	if (list_size == 4)
	{
		ft_pushswap_pb(a, b);
		ft_pushswap_algorithm3(a);
		index_push_a = find_target_position_in_a(*a, *(int *)(*b)->content);
		ft_rotate_stack_to_top(a, index_push_a, 'a');
		ft_pushswap_pa(a, b);
	}
	if (list_size > 4)
		return (ft_pushswap_algorithmturk(a, b));
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

int	main_two(t_list **a, t_list **b, char *argv[])
{
	int		atoi_;
	int		i;
	t_list	*new;

	i = 2;
	while (argv[i])
	{
		atoi_ = ft_atoi(argv[i]);
		new = ft_lstnew(ft_memcpy(malloc(sizeof(int)), &atoi_, sizeof(int)));
		if (!new)
		{
			free(new);
			ft_pushswap_freestack(a, b);
			return (1);
		}
		ft_lstadd_back(a, new);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		atoi_;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || ft_pushswap_error(argv + 1) == 1)
		return (1);
	atoi_ = ft_atoi(argv[1]);
	if (argc > 1)
		a = ft_lstnew(ft_memcpy(malloc(sizeof(int)), &atoi_, sizeof(int)));
	if (!a)
	{
		ft_pushswap_freestack(&a, &b);
		return (1);
	}
	if (main_two(&a, &b, argv) != 0)
		return (1);
	ft_pushswap_prealgorithm(ft_lstsize(a), &a, &b);
	ft_pushswap_finalcheck(&a, &b);
	return (0);
}
