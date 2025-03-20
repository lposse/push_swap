/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:20:50 by lposse            #+#    #+#             */
/*   Updated: 2025/01/09 15:04:08 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_lendest(char *dest)
{
	size_t	len_dest;

	len_dest = 0;
	while (dest[len_dest])
		len_dest++;
	return (len_dest);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	remaining;
	size_t	len_dest;

	len_dest = ft_lendest(dest);
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size > len_dest)
	{
		remaining = size - len_dest - 1;
		i = len_dest;
		while (remaining-- && *src != '\0')
		{
			dest[i] = *src;
			i++;
			src++;
		}
		dest[i] = '\0';
	}
	if (size < len_dest)
		return (len_src + size);
	return (len_dest + len_src);
}
