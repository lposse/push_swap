/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:47:19 by lposse            #+#    #+#             */
/*   Updated: 2025/01/13 18:23:49 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	*ft_dupword(char const *s, int start, int end)
{
	int		len;
	int		i;
	char	*word;

	len = end - start;
	if (len <= 0)
		return (NULL);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_tomanocu(char const *s, char c, int num_words)
{
	int		i;
	int		start;
	int		end;
	int		idx;
	char	**result_array;

	result_array = (char **)ft_calloc((num_words + 1), sizeof(char *));
	if (result_array == NULL)
		return (NULL);
	i = 0;
	idx = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i;
		if (end > start)
			result_array[idx++] = ft_dupword(s, start, end);
	}
	return (result_array);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = ft_count(s, c);
	result = ft_tomanocu(s, c, num_words);
	if (result == NULL)
		return (NULL);
	return (result);
}
