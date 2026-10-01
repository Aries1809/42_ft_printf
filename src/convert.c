/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   convert.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/29 14:15:54 by kseltenr         #+#    #+#              */
/*   Updated: 2026/09/30 20:03:18 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	init_flags(t_flags *flags)
{
	flags->minus = false;
	flags->zero = false;
	flags->sharp = false;
	flags->space = false;
	flags->plus = false;
	flags->width = 0;
	flags->precision = 0
}

size_t	parse_flags(char *str, size_t position, t_flags *flags)
{

}

size_t	parse_width(char *str, size_t position, t_flags *flags)
{

}

size_t	parse_precision(char *str, size_t position, t_flags *flags)
{

}

char	*conversion(char type, t_flags *flags, va_list args)
{
	if (c == "c" || c == "s")
		
	elseif (c == "p")

	elseif (c == "d")

	elseif (c == "i")

	elseif (c == "u")

	elseif (c == "x")

	elseif (c == "X")

	elseif (c == "%")

}
