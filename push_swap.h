/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:54:13 by lposse            #+#    #+#             */
/*   Updated: 2025/03/24 20:55:51 by lposse           ###   ########.fr       */
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

#endif
