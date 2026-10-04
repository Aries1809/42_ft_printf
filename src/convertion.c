/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   convertion.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 17:39:19 by kseltenr         #+#    #+#              */
/*   Updated: 2026/10/05 01:44:14 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

size_t	ft_hexlen(size_t dec)
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

size_t	ft_hex(size_t dec, int check)
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
	ft_putstr_fd(ret, 1);
	free(ret);
	return (ft_hexlen(dec));
}

size_t	ft_putuint_all(unsigned int n, int fd)
{
	if (n > 9)
		ft_putuint_all(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (ft_intlen((long long)n));
}

size_t	ft_memaddr(void *ptr)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	ft_hex(addr, 120);
	return (ft_hexlen(addr) + 2);
}
