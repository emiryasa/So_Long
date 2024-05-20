/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:17:54 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/14 20:33:33 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srcs;

	dst = (unsigned char *)dest;
	srcs = (unsigned char *)src;
	if (!dst && !srcs)
		return (NULL);
	if (dst > srcs)
	{
		while (n-- > 0)
			dst[n] = srcs[n];
	}
	else
	{
		return (ft_memcpy(dest, src, n));
	}
	return (dest);
}
