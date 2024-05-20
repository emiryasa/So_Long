/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:54:38 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/28 16:24:12 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_nbase(long long nbr, const char *str, int base);
int	ft_ptr(void *ptr);
int	ft_printf(const char *str, ...);

#endif