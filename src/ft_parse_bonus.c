/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 21:33:11 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 19:05:13 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf_bonus.h"
#include "libft.h"

static int	pf_atoi(const char **fmt)
{
	int32_t	n;

	n = 0;
	while (ft_isdigit(**fmt))
	{
		n = n * 10 + (**fmt - '0');
		(*fmt)++;
	}
	return (n);
}

static void	pf_set_flag(t_spec *sp, char c)
{
	if (c == '-')
		sp->minus = 1;
	else if (c == '0')
		sp->zero = 1;
	else if (c == '#')
		sp->hash = 1;
	else if (c == ' ')
		sp->space = 1;
	else if (c == '+')
		sp->plus = 1;
}

static void	pf_normalize(t_spec *sp)
{
	if (sp->minus || sp->prec >= 0 || ft_strchr("cs%", sp->conv))
		sp->zero = 0;
	if (!ft_strchr("dip", sp->conv))
	{
		sp->plus = 0;
		sp->space = 0;
	}
	if (!ft_strchr("xX", sp->conv))
		sp->hash = 0;
	if (sp->conv == 'p')
		sp->hash = 1;
}

void	pf_parse(const char **fmt, t_spec *sp)
{
	ft_bzero(sp, sizeof(*sp));
	while (**fmt && ft_strchr(FLAGS, **fmt))
	{
		pf_set_flag(sp, **fmt);
		(*fmt)++;
	}
	sp->width = pf_atoi(fmt);
	sp->prec = -1;
	if (**fmt == '.')
	{
		(*fmt)++;
		sp->prec = pf_atoi(fmt);
	}
	sp->conv = **fmt;
	pf_normalize(sp);
}
