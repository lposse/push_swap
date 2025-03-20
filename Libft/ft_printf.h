/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:04:02 by lposse            #+#    #+#             */
/*   Updated: 2025/02/14 16:17:37 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_printf_char(int c, int i, const char *str, int *count);
void	ft_printf_str(char *str, int *count);
void	ft_printf_int(int c, int i, const char *str, int *count);
void	ft_printf_int_u(unsigned int c, int *count, const char *str, int i);
void	ft_printf_hex(unsigned int hex, int i, const char *str, int *count);
void	ft_printf_ptr(void *ptr, int *count);
void	ft_printf_ptr_rec(uintptr_t address, int *count);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_lenint(int n);

#endif
