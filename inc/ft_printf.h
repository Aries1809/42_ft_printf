/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:27:37 by kseltenr          #+#    #+#             */
/*   Updated: 2026/10/03 15:24:28 by kseltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_hex(unsigned int dec, int check);
size_t	ft_hex_ptr(size_t dec, int check);
size_t	ft_putuint_all(unsigned int n, int fd);
size_t	ft_memaddr(void *ptr);
int		ft_putchar_all(char c, int fd);
size_t	ft_putstr_all(char *s, int fd);
size_t	ft_intlen(long long n);
size_t	ft_putnbr_all(int n, int fd);

#endif
