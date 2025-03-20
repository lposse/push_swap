/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:05:51 by lposse            #+#    #+#             */
/*   Updated: 2025/03/19 18:43:36 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printf_int_u(unsigned int c, int *count, const char *str, int i)
{
	char	digit;

	if (c == (unsigned int)(-2147483648))
	{
		if (str[i + 1] == 'i' || str[i + 1] == 'd')
		{
			ft_putstr("-2147483648");
			(*count) += 11;
			return ;
		}
	}
	if (c >= 10)
		ft_printf_int_u((c / 10), count, str, i);
	digit = (c % 10) + '0';
	write (1, &digit, 1);
	(*count)++;
	return ;
}

void	ft_printf_int(int c, int i, const char *str, int *count)
{
	if ((str[i] == '%' && str[i + 1] == 'u' && c < 0) || c == -2147483648)
	{
		ft_printf_int_u((unsigned int)c, count, str, i);
		return ;
	}
	if (c < 0)
	{
		ft_putchar('-');
		c = -c;
		(*count)++;
	}
	if (c >= 10)
	{
		ft_printf_int(c / 10, i, str, count);
		ft_printf_int(c % 10, i, str, count);
	}
	else
	{
		ft_putchar((c + '0'));
		(*count)++;
	}
}

void	ft_printf_hex(unsigned int hex, int i, const char *str, int *count)
{
	char	*nums;

	if (str[i + 1] == 'x' || str[i + 1] == 'p')
		nums = "0123456789abcdef";
	if (str[i + 1] == 'X')
		nums = "0123456789ABCDEF";
	if (hex >= 16)
		ft_printf_hex(hex / 16, i, str, count);
	ft_putchar(nums[hex % 16]);
	(*count)++;
}

void	ft_printf_ptr_rec(uintptr_t address, int *count)
{
	char	*nums;

	nums = "0123456789abcdef";
	if (address >= 16)
		ft_printf_ptr_rec(address / 16, count);
	ft_putchar(nums[address % 16]);
	(*count)++;
}

void	ft_printf_ptr(void *ptr, int *count)
{
	uintptr_t	address;

	address = (uintptr_t)ptr;
	if (!ptr)
	{
		write (1, "(nil)", 5);
		*count += 5;
		return ;
	}
	write (1, "0x", 2);
	(*count) += 2;
	ft_printf_ptr_rec(address, count);
	return ;
}
