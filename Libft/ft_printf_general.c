/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:56:48 by lposse            #+#    #+#             */
/*   Updated: 2025/03/19 18:43:52 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printf_2(int i, const char *str, va_list args, int *count)
{
	if (str[i] == '%')
	{
		if (str[i + 1] == 's')
			ft_printf_str(va_arg(args, char *), count);
		else if (str[i + 1] == 'p')
			ft_printf_ptr(va_arg(args, void *), count);
		else if (str[i + 1] == '%')
		{
			ft_putchar('%');
			(*count)++;
		}
		else if (str[i + 1] == 'c')
			ft_printf_char(va_arg(args, int), i, str, count);
		else if (str[i + 1] == 'u' || str[i + 1] == 'd'
			|| str[i + 1] == 'i')
			ft_printf_int(va_arg(args, int), i, str, count);
		else if (str[i + 1] == 'x' || str[i + 1] == 'X')
			ft_printf_hex((unsigned int)va_arg(args, int), i, str, count);
		else
		{
			write (1, "%", 1);
			(*count)++;
		}
	}
	return ;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			ft_printf_2(i, str, args, &count);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
