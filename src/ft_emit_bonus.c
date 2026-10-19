/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 21:04:59 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 19:05:40 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_printf_bonus.h"
#include "libft.h"

int	pf_write(const char *s, int32_t len)
{
	if (len <= 0)
		return (0);
	return (write(1, s, len));
}

int	pf_pad(char c, int32_t n)
{
	int32_t	i;

	i = 0;
	while (i < n)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	pf_emit_str(t_spec *sp, const char *s, int32_t len)
{
	int32_t	pad;

	pad = sp->width - len;
	if (pad < 0)
		pad = 0;
	if ((!sp->minus && pf_pad(' ', pad) < 0)
		|| pf_write(s, len) < 0
		|| (sp->minus && pf_pad(' ', pad) < 0))
		return (-1);
	return (pad + len);
}

int	pf_emit_nbr(t_spec *sp, const char *pre, const char *num, int32_t len)
{
	int32_t	plen;
	int32_t	zeros;
	int32_t	pad;

	plen = ft_strlen(pre);
	zeros = sp->prec - len;
	if (sp->zero)
		zeros = sp->width - plen - len;
	if (zeros < 0)
		zeros = 0;
	pad = sp->width - plen - zeros - len;
	if (pad < 0)
		pad = 0;
	if ((!sp->minus && pf_pad(' ', pad) < 0)
		|| pf_write(pre, plen) < 0
		|| pf_pad('0', zeros) < 0
		|| pf_write(num, len) < 0
		|| (sp->minus && pf_pad(' ', pad) < 0))
		return (-1);
	return (pad + plen + zeros + len);
}
