/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/28 13:04:45 by kseltenr         #+#    #+#              */
/*   Updated: 2026/09/29 13:55:53 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h> // va_start va_arg va_end ca_copy va_list

char	*convert(*cmd)
{
	
}

char	*parse_string(const char *str)
{
	char	**s_str;
	int		i;

	i = 0;
	s_str = ft_split(str, '%');
	if (!s_str)
		return (NULL);
	while (s_str[i++])
		s_str[i] = convert(s_str[i]);
}
int	ft_printf(const char *input, ...)
{
	char	*ret;

	ret = parse_string(input);
}
