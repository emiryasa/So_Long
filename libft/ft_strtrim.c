/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:06:30 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/10 19:09:46 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check(*s1, set) == 1)
			s1++;
		else
			break ;
	}
	end = ft_strlen(s1);
	while (end != 0)
	{
		if (ft_check(s1[end - 1], set) == 1)
			end--;
		else
			break ;
	}
	dst = (char *)malloc(end * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, (char *)s1, end + 1);
	return (dst);
}
