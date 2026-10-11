/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:27:37 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/11 15:11:12 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

size_t		ft_hex(size_t dec, int check);
size_t		ft_intlen(long long n);
size_t		ft_memaddr(void *ptr);
int			ft_printf(const char *format, ...);
size_t		ft_putchar_all(char c, int fd);
size_t		ft_putnbr_all(long long n, int fd);
size_t		ft_putstr_all(char *s, int fd);

#endif
