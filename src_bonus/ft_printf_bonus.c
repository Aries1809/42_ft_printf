/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_bonus.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/06 15:14:09 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/08 13:59:51 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

size_t	flag_check(const char *format, t_flag *flags, size_t *length)
{
	size_t	cnt;
	char	*buf;

	cnt = 0;
	if (*format == '0' || *format == '-' || *format == '.')
	{
		buf = malloc(4096);
		while (ft_isdigit(format[cnt++]))
			buf[cnt] = format[cnt];
		buf[4095] = '\0';
		if (*format == '0')
			flags->zero = ft_atoi(buf);
		if (*format == '-')
			flags->minus = ft_atoi(buf);
		if (*format == '.')
			flags->dot = ft_atoi(buf);
		free(buf);
	}
	*length += cnt;
	return (cnt);
}

void	flag_apply(t_flag *flags)
{
	while (flags->zero != 0)
	{
		ft_putchar_fd('0', 1);
		flags->zero--;
	}
	while (flags->minus != 0)
	{
		flags->minus--;
	}
	while (flags->dot != 0)
	{
		flags->dot--;
	}
}

size_t	ft_handle(const char *format, va_list args, t_flag *flags)
{
	size_t	cnt;

	cnt = 0;
	format += flag_check(format, &*flags, &cnt);
	flag_apply(&*flags);
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
	if (!flags)
		return ;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;
	t_flag	flags;

	init_flags(&flags);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar_all(*format, 1);
		else
		{
			format++;
			len += ft_handle(format, args, &flags);
		}
		format++;
	}
	va_end(args);
	return (len);
}
