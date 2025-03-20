/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:47:19 by lposse            #+#    #+#             */
/*   Updated: 2025/01/08 18:19:08 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	array = (char *)malloc((i + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
