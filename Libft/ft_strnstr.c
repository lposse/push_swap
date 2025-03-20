/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:09:19 by lposse            #+#    #+#             */
/*   Updated: 2025/01/13 17:56:57 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (big == NULL || little == NULL)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0' || n <= 0)
		return (NULL);
	i = 0;
	while (i < n && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while ((i + j) < n && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
