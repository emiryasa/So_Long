/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:55:28 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/28 16:49:29 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (str == NULL)
		counter += ft_putstr("(null)");
	else
	{
		while (str[i])
		{
			counter += ft_putchar(str[i]);
			i++;
		}
	}
	return (counter);
}

int	ft_nbase(long long nbr, const char *str, int base)
{
	int	counter;

	counter = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		counter++;
	}
	if (nbr >= base)
	{
		counter += ft_nbase(nbr / base, str, base);
	}
	counter += write(1, &str[nbr % base], 1);
	return (counter);
}

int	ft_ptr(void *ptr)
{
	int					counter;
	unsigned long long	nbr;

	counter = 0;
	nbr = (unsigned long long)ptr;
	if (nbr >= 16)
	{
		counter += ft_nbase(nbr / 16, "0123456789abcdef", 16);
	}
	counter += write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (counter);
}
