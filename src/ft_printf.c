/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:05:20 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 21:15:22 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"
 
static int	pf_dispatch(char c, va_list *ap)
{
	int64_t	n;
 
	if (c == 'c')
		return (pf_putchar(va_arg(*ap, int)));
	if (c == 's')
		return (pf_putstr(va_arg(*ap, const char *)));
	if (c == 'p')
		return (pf_putptr(va_arg(*ap, void *)));
	if (c == 'd' || c == 'i')
	{
		n = va_arg(*ap, int);
		if (n < 0)
			return (pf_putnbr(-n, DECIMAL, "-"));
		return (pf_putnbr(n, DECIMAL, ""));
	}
	if (c == 'u')
		return (pf_putnbr(va_arg(*ap, unsigned int), DECIMAL, ""));
	if (c == 'x')
		return (pf_putnbr(va_arg(*ap, unsigned int), HEX_LOWER, ""));
	if (c == 'X')
		return (pf_putnbr(va_arg(*ap, unsigned int), HEX_UPPER, ""));
	return (write(1, "%", 1));
}
 
static int	pf_print_chunk(const char **fmt, va_list *ap)
{
	const char	*start;
 
	start = *fmt;
	(*fmt)++;
	if (*start == '%')
	{
		if (!**fmt)
			return (-1);
		if (ft_strchr(CONVERSIONS, **fmt))
		{
			(*fmt)++;
			return (pf_dispatch(start[1], ap));
		}
	}
	while (**fmt && **fmt != '%')
		(*fmt)++;
	return (write(1, start, *fmt - start));
}
 
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int32_t	count;
	int32_t	ret;
 
	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	ret = 0;
	while (*format && ret >= 0)
	{
		ret = pf_print_chunk(&format, &ap);
		count += ret;
	}
	va_end(ap);
	if (ret < 0)
		return (-1);
	return (count);
}
