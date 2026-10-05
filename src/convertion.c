/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   convertion.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 17:39:19 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/05 15:55:10 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

size_t	ft_hexlen(unsigned int dec)
{
	size_t	ret;

	ret = 0;
	while (dec > 0)
	{
		ret++;
		dec /= 16;
	}
	return (ret);
}

size_t	ft_hex(unsigned int dec, int check)
{
	char	*ret;
	char	*hex_l;
	char	*hex_u;
	int		cnt;

	if (dec == 0)
		return (ft_putstr_all("0", 1));
	cnt = ft_hexlen(dec);
	hex_l = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	ret = malloc(cnt + 1);
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	while (--cnt >= 0)
	{
		if (check == 120)
			ret[cnt] = hex_l[dec % 16];
		else if (check == 88)
			ret[cnt] = hex_u[dec % 16];
		dec /= 16;
	}
	cnt = ft_putstr_all(ret, 1);
	free(ret);
	return (cnt);
}

size_t	ft_hexlen_ptr(size_t dec)
{
	size_t	ret;

	ret = 0;
	while (dec > 0)
	{
		ret++;
		dec /= 16;
	}
	return (ret);
}

size_t	ft_hex_ptr(size_t dec, int check)
{
	char	*ret;
	char	*hex_l;
	char	*hex_u;
	int		cnt;

	if (dec == 0)
		return (ft_putstr_all("0", 1));
	cnt = ft_hexlen_ptr(dec);
	hex_l = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	ret = malloc(cnt + 1);
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	while (--cnt >= 0)
	{
		if (check == 120)
			ret[cnt] = hex_l[dec % 16];
		else if (check == 88)
			ret[cnt] = hex_u[dec % 16];
		dec /= 16;
	}
	cnt = ft_putstr_all(ret, 1);
	free(ret);
	return (cnt);
}

size_t	ft_memaddr(void *ptr)
{
	uintptr_t	addr;

	if (!ptr)
		return (ft_putstr_all("(nil)", 1));
	addr = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	ft_hex_ptr(addr, 120);
	return (ft_hexlen_ptr(addr) + 2);
}
