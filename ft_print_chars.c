/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:42:04 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/18 15:37:05 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Prints a char
int	ft_putchar_int(const char c)
{
	return (write(1, &c, 1));
}

// Prints a string
int	ft_putstr_int(const char *str)
{
	int	i;
	int	check;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		check = ft_putchar_int(str[i]);
		if (check == -1)
			return (-1);
		i++;
	}
	return (i);
}

//Prints array of chars for hex, int, unsigned int, address
int	ft_print(int index, const char *c)
{
	int	len;
	int	result;

	len = 0;
	index--;
	result = 0;
	while (index >= 0)
	{
		result = ft_putchar_int(c[index]);
		if (result == -1)
			return (-1);
		len += result;
		index--;
	}
	return (len);
}
