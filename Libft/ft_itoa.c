/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:37:19 by lposse            #+#    #+#             */
/*   Updated: 2025/01/09 17:13:03 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
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

static char	*ft_itoa_intmin(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_n0(void)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	if (n == INT_MIN)
		return (ft_itoa_intmin());
	len = ft_len(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
		return (ft_n0());
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	result[len] = '\0';
	while (n > 0)
	{
		result[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
