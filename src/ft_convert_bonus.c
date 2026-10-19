/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:44:43 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 21:14:05 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf_bonus.h"
#include "libft.h"
 
static char	*pf_utoa(t_spec *sp, uint64_t n, char *end)
{
	const char	*digits;
	uint64_t	base;
 
	digits = "0123456789abcdef";
	if (sp->conv == 'X')
		digits = "0123456789ABCDEF";
	base = 16;
	if (ft_strchr("diu", sp->conv))
		base = 10;
	if (n == 0 && sp->prec != 0)
		*--end = '0';
	while (n)
	{
		*--end = digits[n % base];
		n /= base;
	}
	return (end);
}
 
static void	pf_prefix(t_spec *sp, uint64_t n, int32_t neg, char *pre)
{
	*pre = '\0';
	if (neg)
		ft_strlcat(pre, "-", 4);
	else if (sp->plus)
		ft_strlcat(pre, "+", 4);
	else if (sp->space)
		ft_strlcat(pre, " ", 4);
	if (sp->hash && n && sp->conv == 'X')
		ft_strlcat(pre, "0X", 4);
	else if (sp->hash && n)
		ft_strlcat(pre, "0x", 4);
}
 
int	pf_convert_nbr(t_spec *sp, uint64_t n, int32_t neg)
{
	char	buf[20];
	char	pre[4];
	char	*num;
 
	if (sp->conv == 'p' && !n)
		return (pf_emit_str(sp, "(nil)", 5));
	num = pf_utoa(sp, n, buf + sizeof(buf));
	pf_prefix(sp, n, neg, pre);
	return (pf_emit_nbr(sp, pre, num, buf + sizeof(buf) - num));
}
 
int	pf_convert_str(t_spec *sp, const char *s)
{
	int32_t	len;
 
	if (!s && sp->prec >= 0 && sp->prec < 6)
		s = "";
	else if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (sp->prec >= 0 && sp->prec < len)
		len = sp->prec;
	return (pf_emit_str(sp, s, len));
}
