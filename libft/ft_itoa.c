/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:58:25 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/07 18:27:30 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	*dest;

	num = n;
	i = ft_length(num);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i--] = '\0';
	if (num == 0)
		return (dest[0] = '0', dest);
	if (num < 0)
	{
		dest[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		dest[i--] = (num % 10) + 48;
		num /= 10;
	}
	return (dest);
}
