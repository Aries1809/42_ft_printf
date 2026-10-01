/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:35:01 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 16:50:26 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef	struct s_flags
{
	bool	minus;
	bool	zero;
	bool	sharp;
	bool	space;
	bool	plus;
	int		width;
	int		precision;
}	t_flags;

int	ft_printf(const char *input, ...);
size_t	parse_flags(char *str, size_t position, t_flags *flags);
size_t	parse_width(char *str, size_t position, t_flags *flags);
size_t	parse_precision(char *str, size_t position, t_flags *flags);
char	*convertion(char c, t_flags *flags, va_list args);

#endif
