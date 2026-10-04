/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 16:18:40 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/05 01:50:20 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h> // va_list va_start va_arg va_copy va_end

size_t	ft_handle(const char *format, va_list args)
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
		cnt += ft_putuint_all(va_arg(args, unsigned int), 1);
	else if (*format == 'x' || *format == 'X')
		cnt += ft_hex(va_arg(args, size_t), (int)(*format));
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

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar_all(*format, 1);
		else
		{
			format++;
			len += ft_handle(format, args);
		}
		format++;
	}
	va_end(args);
	return (len);
}
