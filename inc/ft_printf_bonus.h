/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:29:38 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 21:11:28 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-0# +"

# include <stdint.h>

typedef struct s_spec
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		prec;
	char	conv;
}	t_spec;

int		ft_printf(const char *format, ...);
int		pf_convert_nbr(t_spec *sp, uint64_t n, int32_t neg);
int		pf_convert_str(t_spec *sp, const char *s);
int		pf_emit_nbr(t_spec *sp, const char *pre, const char *num, int32_t len);
int		pf_emit_str(t_spec *sp, const char *s, int32_t len);
int		pf_pad(char c, int32_t n);
void	pf_parse(const char **fmt, t_spec *sp);
int		pf_write(const char *s, int32_t len);

#endif
