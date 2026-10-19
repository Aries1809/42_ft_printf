/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:05:34 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 19:05:37 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

int	pf_putchar(int c)
{
	uint32_t	ch;

	ch = c;
	return (write(1, &ch, 1));
}

int	pf_putstr(const char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}

int	pf_putptr(void *ptr)
{
	if (!ptr)
		return (pf_putstr("(nil)"));
	return (pf_putnbr((uint64_t)ptr, HEX_LOWER, "0x"));
}

int	pf_putnbr(unsigned long n, const char *base, const char *prefix)
{
	char	buf[32];
	char	*start;
	size_t	radix;
	size_t	plen;

	radix = ft_strlen(base);
	start = buf + sizeof(buf);
	if (n == 0)
		*--start = '0';
	while (n)
	{
		*--start = base[n % radix];
		n /= radix;
	}
	plen = ft_strlen(prefix);
	start -= plen;
	ft_memcpy(start, prefix, plen);
	return (write(1, start, buf + sizeof(buf) - start));
}
