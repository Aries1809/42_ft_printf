/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/28 13:04:45 by kseltenr         #+#    #+#              */
/*   Updated: 2026/09/30 20:01:47 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h> // va_start va_arg va_end ca_copy va_list

size_t	handel_conv(char *str, size_t position, va_list args)
{
	t_flags	flags;
	size_t	start;
	char	*temp;

	start = position;
	position++;
	init_flags(&flags);
	position = parse_flags(str, position, &flags);
	position = parse_width(str, position, &flags);
	position = parse_precision(str,position, &flags);
	temp = ft_strdup(convertion(str[position], &flags, args));
}

char	*parse_string(char *str, va_list args)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] != '%')
			ft_putchar_fd(str[counter], 1);
		else
			handel_conv(&*str, counter, args);
		counter++;
	}
}

int	ft_printf(const char *input, ...)
{
	char	*ret;
	va_list	args;
	char	*str;

	str = ft_strdup(input);
	ret = parse_string(str, args);
}
