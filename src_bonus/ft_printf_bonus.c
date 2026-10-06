/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_bonus.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/06 15:14:09 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/06 15:52:49 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

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

void	init_flags(t_flag *flags)
{

}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;
	t_flag	flags;

	init_flags(&flags)
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
