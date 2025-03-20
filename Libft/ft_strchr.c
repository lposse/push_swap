/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:16:45 by lposse            #+#    #+#             */
/*   Updated: 2025/01/09 16:19:05 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	if (!s)
		return (NULL);
	if (c < 0 || c > 255)
		return (NULL);
	ptr_s = (char *)s;
	while (*ptr_s != '\0')
	{
		if (*ptr_s == (char)c)
			return (ptr_s);
		ptr_s++;
	}
	if (c == '\0')
		return (ptr_s);
	return (NULL);
}
