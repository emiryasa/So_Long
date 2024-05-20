/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:16:55 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/28 16:54:51 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_vartype(char c, va_list arg)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(arg, int));
	else if (c == 'd' || c == 'i')
		counter += ft_nbase(va_arg(arg, int), "0123456789", 10);
	else if (c == 'u')
		counter += ft_nbase(va_arg(arg, unsigned int), "0123456789", 10);
	else if (c == 's')
		counter += ft_putstr(va_arg(arg, char *));
	else if (c == '%')
		counter += ft_putchar('%');
	else if (c == 'x')
		counter += ft_nbase(va_arg(arg, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		counter += ft_nbase(va_arg(arg, unsigned int), "0123456789ABCDEF", 16);
	else if (c == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_ptr(va_arg(arg, void *));
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			counter += ft_vartype(str[i + 1], arg);
			i++;
		}
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (counter);
}
