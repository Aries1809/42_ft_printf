/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/28 13:04:45 by kseltenr         #+#    #+#              */
/*   Updated: 2026/09/30 14:15:23 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h> // va_start va_arg va_end ca_copy va_list

char	*parse_string(char *str)
{
	size_t	counter;

	counter = 0;
	while(str[counter++])
	{
		if (str[counter] != '%')
			ft_putchar_fd(str[counter], 1);
		else
	}
}

int	ft_printf(const char *input, ...)
{
	char	*ret;

	va_list args;

	ret = parse_string(input);
}
