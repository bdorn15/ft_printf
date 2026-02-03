/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:04:01 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/20 11:35:19 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints Adress
static int	ft_print_ptr(uintptr_t n)
{
	char		ulong[16];
	int			len;
	int			i;
	const char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (n == 0)
		return (ft_putchar_int('0'));
	i = 0;
	while (n > 0)
	{
		ulong[i++] = hex[n % 16];
		n /= 16;
	}
	len = ft_print(i, ulong);
	return (len);
}

// Handles Adress Value
int	ft_print_add(const void *ptr)
{
	int				r;
	uintptr_t		address;

	r = 0;
	if (ptr == NULL)
		return (ft_putstr_int("(nil)"));
	address = (uintptr_t)ptr;
	r = ft_putstr_int("0x");
	if (r == -1)
		return (-1);
	r = ft_print_ptr(address);
	if (r == -1)
		return (-1);

	return (2 + r);
}

// Converts number to hexadecimal
int	ft_print_hex(unsigned int n, const char *base)
{
	char	hex[8];
	int		len;
	int		i;

	if (n == 0)
		return (ft_putchar_int(base[0]));
	i = 0;
	len = 0;
	while (n > 0)
	{
		hex[i++] = base[n % 16];
		n /= 16;
	}
	len = ft_print(i, hex);
	return (len);
}
