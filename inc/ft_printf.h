/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:05:28 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/19 21:10:13 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSIONS "cspdiuxX%"
# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# include <stdint.h>

int	ft_printf(const char *format, ...);
int	pf_putchar(int c);
int	pf_putnbr(uint64_t n, const char *base, const char *prefix);
int	pf_putptr(void *ptr);
int	pf_putstr(const char *s);

#endif
