/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:58:38 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/15 15:53:42 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dest;

	i = 0;
	j = 0;
	dest = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i + k] && s[i + k] != c)
				k++;
			dest[j++] = ft_substr(s + i, 0, k);
			i += k;
		}
		else
			i++;
	}
	dest[j] = NULL;
	return (dest);
}
