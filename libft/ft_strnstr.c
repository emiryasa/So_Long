/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:48:24 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/08 21:10:15 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (to_find[0] == '\0' || to_find == str)
		return ((char *)str);
	while (str[i])
	{
		n = 0;
		while (str[i + n] == to_find[n] && i + n < len)
		{
			if (str[i + n] == '\0' && to_find[n] == '\0')
				return ((char *)&str[i]);
			n++;
		}
		if (to_find[n] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
