/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   convertion.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 17:39:19 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/11 04:46:21 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

size_t	ft_hex(size_t dec, int check)
{
	char	buf[17];
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	if (check == 'X')
		hex = "0123456789ABCDEF";
	if (dec == 0)
		return (ft_putstr_all("0", 1));
	i = 16;
	buf[i] = '\0';
	while (dec > 0)
	{
		buf[--i] = hex[dec % 16];
		dec /= 16;
	}
	return (ft_putstr_all(buf + i, 1));
}

size_t	ft_memaddr(void *ptr)
{
	uintptr_t	addr;

	if (!ptr)
		return (ft_putstr_all("(nil)", 1));
	addr = (uintptr_t)ptr;
	return (ft_putstr_all("0x", 1) + ft_hex(addr, 'x'));
}
