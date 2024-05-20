/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:17:46 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/14 18:13:34 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	s = 0;
	srclen = ft_strlen(src);
	if (!dest && dstsize == 0)
		return (srclen);
	i = ft_strlen(dest);
	destlen = i;
	if (dstsize <= destlen)
		return (dstsize + srclen);
	while (src[s] && i < dstsize - 1)
	{
		dest[i] = src[s];
		s++;
		i++;
	}
	dest[i] = 0;
	return (destlen + srclen);
}
