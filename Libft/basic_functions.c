/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:55:56 by lposse            #+#    #+#             */
/*   Updated: 2025/03/19 18:43:13 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_lenint(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_printf_char(int c, int i, const char *str, int *count)
{
	char	x;

	if (str[i] == '%' && str[i + 1] == 'c')
	{
		x = (char)c;
		ft_putchar(x);
		(*count)++;
	}
}

void	ft_printf_str(char *str, int *count)
{
	int	len;

	if (!str)
	{
		ft_putstr("(null)");
		*count += 6;
		return ;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr(str);
		*count += len;
	}
	return ;
}
