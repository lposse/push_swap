/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:01:31 by lposse            #+#    #+#             */
/*   Updated: 2025/03/20 22:02:41 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_push_swap3ints(t_list *a, t_list *b)
{
	int	*content;

	1 2 3
	o content de nodo 1 > content de nodo 2

}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*new_node;
	int		i;
	int		list_size;
	
	b = ft_lstnew(NULL);
	a = NULL;
	if (argc > 1)
		a = ft_lstnew((void *)(long)ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		new_node = ft_lstnew((void *)(long)ft_atoi(argv[i]));
		ft_lstadd_front(&a, new_node);
		i++;
	}
	list_size = ft_lstsize(a);
	/*if (list_size == 3)
		ft_push_swap3ints(a, b);

	CALCULAR POSICOES CORRETAS;
	EXECUTAR COMANDOS (retorno dos comandos na propria funcao);
	imprimir comandos utilizados
	*/
	return (0);
}

