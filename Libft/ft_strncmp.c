/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:47:19 by lposse            #+#    #+#             */
/*   Updated: 2025/01/08 21:32:31 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	size_t			i;

	if (!s1 || !s2 || !n)
		return (0);
	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1)
	{
		if (ptrs1[i] != ptrs2[i])
			return ((int)(ptrs1[i] - ptrs2[i]));
		if (ptrs1[i] == '\0' || ptrs2[i] == '\0')
			break ;
		i++;
	}
	return ((int)(ptrs1[i] - ptrs2[i]));
}
