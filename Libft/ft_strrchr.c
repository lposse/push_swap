/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:29:26 by lposse            #+#    #+#             */
/*   Updated: 2025/01/01 19:46:17 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_s;
	int		len;

	ptr_s = (char *)s;
	len = 0;
	while (ptr_s[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (ptr_s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
