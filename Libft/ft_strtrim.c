/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:19 by lposse            #+#    #+#             */
/*   Updated: 2025/01/08 18:08:58 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;
	int		i;

	ptr_s = (char *)s;
	i = 0;
	while (ptr_s[i] != '\0' && ptr_s[i] != (char)c)
		i++;
	if (ptr_s[i] == (char)c)
		return ((char *)&ptr_s[i]);
	else
		return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	len = start;
	while (s1[len] != '\0')
		len++;
	end = len - 1;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	result = (char *)malloc((end - start + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	len = 0;
	while (start <= end)
		result[len++] = s1[start++];
	result[len] = '\0';
	return (result);
}
