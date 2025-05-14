/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:54:13 by lposse            #+#    #+#             */
/*   Updated: 2025/05/14 17:27:52 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>

void	ft_pushswap_sa(t_list **a);
void	ft_pushswap_sb(t_list **b);
void	ft_pushswap_ss(t_list **a, t_list **b);
void	ft_pushswap_pa(t_list **a, t_list **b);
void	ft_pushswap_pb(t_list **a, t_list **b);
void	ft_pushswap_ra(t_list **a);
void	ft_pushswap_rb(t_list **b);
void	ft_pushswap_rr(t_list **a, t_list **b);
void	ft_pushswap_rra(t_list **a);
void	ft_pushswap_rrb(t_list **b);
void	ft_pushswap_rrr(t_list **a, t_list **b);
void	ft_pushswap_prealgorithm(int list_size, t_list **a, t_list **b);
void	ft_pushswap_algorithm3(t_list **a);
int		ft_is_positive_int(char *str);
int		ft_pushswap_error(char *argv[]);
int		find_cheapest_element(t_list **a, t_list **b, int *cheap, int *rr_rrr);
void	ft_pushswap_algorithmturk(t_list **a, t_list **b);
void	ft_pushswap_algorithmturk2(t_list **a, t_list **b);
int		ft_lst_intmax_index(t_list *a);
int		ft_lst_intmax(t_list *a);
int		ft_lst_intmin_index(t_list *a);
int		ft_lst_intmin(t_list *a);
int		ft_lst_findindex_ofint(t_list *a, int c);
void	ft_pushswap_freestack(t_list **a, t_list **b);
int		ft_pushswap_check_is_sorted(t_list **a);
void	*ft_lst_findcontent_byindex(t_list *a, int index);
t_list	*ft_lst_findnode_byindex(t_list *a, int index);
int		ft_pushswap_findplace_pa(t_list *a, int num_to_push);
int		ft_pushswap_findplace_pb(t_list *b, int num_to_push);
int		calc_moves_to_top_a(t_list *a, int element_index);
int		calc_moves_to_position_b(t_list *b, int target_pos);
int		find_target_position_in_b(t_list *b, int node_content);
int		ft_calc_totalmoves(t_list **a, t_list **b, int index_a, int *rr_rrr);
void	ft_calc_totalmoves2(int *movestop_a, int *moves_b, int *rr_rrr);
void	ft_doublerotations(t_list **a, t_list **b, int *idx_a, int *rr_rrr);
void	ft_rotate_stack_to_top(t_list **stack, int index, char stack_name);
void	execute_optimal_moves(t_list **a, t_list **b, int index_a, int rr_rrr);
int		find_target_position_in_a(t_list *a, int value);
int		ft_pushswap_finalcheck(t_list **a, t_list **b);
int		ft_abs(int a);

#endif
