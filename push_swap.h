/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:54:13 by lposse            #+#    #+#             */
/*   Updated: 2025/04/01 21:52:32 by lposse           ###   ########.fr       */
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
void	ft_pushswap_algorithm2(t_list **a);
void	ft_pushswap_algorithm3(t_list **a);
int		ft_is_positive_int(char *str);
int		ft_pushswap_error(char *argv[]);
void	ft_pushswap_algorithm4(t_list **a, t_list **b);
void	ft_pushswap_algorithm4_x3o4xx(t_list **a, t_list **b, int c2, int c3, int c4);
void	ft_pushswap_algorithm4_4o3o2xxx(t_list **a, t_list **b, int c2, int c3, int c4);
void	ft_pushswap_algorithm4_x1(t_list **a, t_list **b, int c1, int c3, int c4);
void	ft_pushswap_algorithm4_pb3pa(t_list **a, t_list **b);
int		find_cheapest_element(t_list *a, t_list *b, int *cheapest_pos);
void	ft_pushswap_algorithmturk(t_list **a, t_list **b);
int		ft_lst_intmax_index(t_list *a);
int		ft_lst_intmax(t_list *a);
int		ft_lst_intmin_index(t_list *a);
int		ft_lst_intmin(t_list *a);
int		ft_lst_findindex_ofint(t_list *a, int c);
void	ft_pushswap_freestack(t_list **a, t_list **b);
int		ft_pushswap_check_is_sorted(t_list **a);
void	*ft_lst_findcontent_byindex(t_list *a, int index);
int		ft_pushswap_findplace_pa(t_list *a, int num_to_push);
int		ft_pushswap_findplace_pb(t_list *b, int num_to_push);
int		calc_moves_to_top_a(t_list *a, int element_index);
int		calc_moves_to_position_b(t_list *b, int target_pos);
int		find_target_position_in_b(t_list *b, int node_content, int max_index, int min_index);
int		ft_pushswap_calculate_totalmoves(t_list *a, t_list *b, int index_a, int max_pos_b, int min_pos_b);
void	execute_optimal_moves(t_list **a, t_list **b, int index_node_a, int max_index_b, int min_index_b);
int		ft_pushswap_finalcheck(t_list **a, t_list **b);

#endif
