/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:41:45 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/20 11:32:59 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Converts int into array
int	ft_print_int(int n)
{
	char	integer[11];
	int		len;
	int		i;
	int		r;

	i = 0;
	len = 0;
	if (n == 0)
		return (ft_putchar_int('0'));
	if (n == INT_MIN)
		return (ft_putstr_int("-2147483648"));
	if (n < 0)
	{
		r = ft_putchar_int('-');
		if (r == -1) 
			return (-1);
		len += r;
		n = -n;
	}
	while (n > 0)
	{
		integer[i++] = (n % 10) + '0';
		n /= 10;
	}
	r = ft_print(i, integer);
	if (r == -1)
		return (-1);
	len += r;
	return (len);
}

// Converts uint into array
int	ft_print_uint(unsigned int n)
{
	char	uint[10];
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar_int('0'));
	while (n > 0)
	{
		uint[i++] = (n % 10) + '0';
		n /= 10;
	}
	len = ft_print(i, uint);
	return (len);
}
