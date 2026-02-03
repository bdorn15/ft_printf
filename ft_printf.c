/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:41:52 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/20 11:31:08 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_conv(va_list *args, char c)
{
	int	r;

	if (c == 'c')
		r = ft_putchar_int((char)va_arg(*args, int));
	else if (c == 's')
		r = ft_putstr_int(va_arg(*args, char *));
	else if (c == 'p')
		r = ft_print_add(va_arg(*args, void *));
	else if (c == 'i' || c == 'd')
		r = ft_print_int(va_arg(*args, int));
	else if (c == 'u')
		r = ft_print_uint(va_arg(*args, unsigned int));
	else if (c == 'X')
		r = ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == 'x')
		r = ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == '%')
		r = ft_putchar_int('%');
	else
		r = 0;
	return (r);
}

static int	check_ifconv(const char c)
{
	const char	*format_list;

	format_list = "cspdiuxX";
	if (c == '%')
		return (1);
	while (*format_list)
	{
		if (c == *format_list)
			return (1);
		format_list++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total;
	int		r;

	total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) && check_ifconv(*(str + 1)))
		{
			r = check_conv(&args, *(str + 1));
			if (r == -1)
				return (va_end(args), -1);
			total += r;
			str += 2;
			continue;
		}
		r = ft_putchar_int(*str);
		if (r == -1)
			return (va_end(args), -1);
		total += r;
		str++;
	}
	va_end(args);
	return (total);
}
