/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:08:49 by lposse            #+#    #+#             */
/*   Updated: 2024/12/30 20:21:37 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (n == 0)
		return (len);
	i = 0;
	while (n-- > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
