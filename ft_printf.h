/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:41:59 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/18 14:58:28 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_putstr_int(const char *str);
int	ft_putchar_int(const char c);
int	ft_printf(const char *str, ...);
int	ft_print_int(int n);
int	ft_print_hex(unsigned int n, const char *base);
int	ft_print_uint(unsigned int n);
int	ft_print_add(const void *ptr);
int	ft_print(int index, const char *c);

#endif
