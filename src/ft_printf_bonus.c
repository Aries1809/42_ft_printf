/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:29:30 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 21:14:52 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <stdint.h>
#include "ft_printf_bonus.h"
#include "libft.h"
 
static int	pf_dispatch(t_spec *sp, va_list *ap)
{
	int64_t	n;
	char	c;
 
	if (sp->conv == 'c')
	{
		c = va_arg(*ap, int);
		return (pf_emit_str(sp, &c, 1));
	}
	if (sp->conv == 's')
		return (pf_convert_str(sp, va_arg(*ap, const char *)));
	if (sp->conv == 'p')
		return (pf_convert_nbr(sp, (uintptr_t)va_arg(*ap, void *), 0));
	if (sp->conv == 'd' || sp->conv == 'i')
	{
		n = va_arg(*ap, int);
		if (n < 0)
			return (pf_convert_nbr(sp, -n, 1));
		return (pf_convert_nbr(sp, n, 0));
	}
	if (sp->conv == '%')
		return (pf_write("%", 1));
	return (pf_convert_nbr(sp, va_arg(*ap, unsigned int), 0));
}
 
static int	pf_print_chunk(const char **fmt, va_list *ap)
{
	const char	*start;
	t_spec		sp;
 
	start = *fmt;
	(*fmt)++;
	if (*start == '%')
	{
		pf_parse(fmt, &sp);
		if (!sp.conv)
			return (-1);
		if (ft_strchr(CONVERSIONS, sp.conv))
		{
			(*fmt)++;
			return (pf_dispatch(&sp, ap));
		}
		*fmt = start + 1;
	}
	while (**fmt && **fmt != '%')
		(*fmt)++;
	return (pf_write(start, *fmt - start));
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
