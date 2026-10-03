/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 16:18:40 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/03 21:29:21 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h> // va_list va_start va_arg va_copy va_end

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	alen;

	alen = count_args(format);
	va_start(args, alen);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1);
		else
		{
			format++;
			if (*format == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (*format == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*format == 'u')
				ft_putuint_fd(va_arg(args, unsigned int), 1);
			else if (*format == 'x' || *format == 'X')
				ft_putstr_fd(ft_hex(va_arg(args, size_t), (int)(*format)), 1);
			else if (*format == '%')
				ft_putchar_fd('%', 1);
			else if (*format == 'p')
				// code
		}
		format++;
	}
	va_end(args);
}
