/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 16:18:40 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/11 15:12:47 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdarg.h>

static size_t	ft_handle(const char *format, va_list args)
{
	size_t	cnt;

	cnt = 0;
	if (*format == 'c')
		cnt += ft_putchar_all(va_arg(args, int), 1);
	else if (*format == 's')
		cnt += ft_putstr_all(va_arg(args, char *), 1);
	else if (*format == 'd' || *format == 'i')
		cnt += ft_putnbr_all(va_arg(args, int), 1);
	else if (*format == 'u')
		cnt += ft_putnbr_all(va_arg(args, unsigned int), 1);
	else if (*format == 'x' || *format == 'X')
		cnt += ft_hex(va_arg(args, unsigned int), (int)(*format));
	else if (*format == '%')
		cnt += ft_putchar_all('%', 1);
	else if (*format == 'p')
		cnt += ft_memaddr(va_arg(args, void *));
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar_all(*format, 1);
		else
		{
			if (!format[1])
				break ;
			format++;
			len += ft_handle(format, args);
		}
		format++;
	}
	va_end(args);
	return (len);
}
